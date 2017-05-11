// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include "orca_tidy/ctor_comment_remover.h"

#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "orca_tidy/string_writer.h"

class CtorCommentRemoverTest : public ::testing::Test {
 protected:
  StringWriter stringWriter_;
  std::stringstream input_;
  const std::string emptyLine_{"\n"};
};

TEST_F(CtorCommentRemoverTest, ItKeepsEmptyLine) {
  input_ << emptyLine_;

  CtorCommentRemover ctorCommentRemover;
  ctorCommentRemover.Remove(input_, &stringWriter_);

  ASSERT_EQ(emptyLine_, stringWriter_.Str());
}

TEST_F(CtorCommentRemoverTest, ItRemovesCtorComments) {
  const std::string ctorLine{"//  ctor\n//  Ctor\n\n"};
  input_ << ctorLine;

  CtorCommentRemover ctorCommentRemover;
  ctorCommentRemover.Remove(input_, &stringWriter_);

  ASSERT_EQ(emptyLine_, stringWriter_.Str());
}

TEST_F(CtorCommentRemoverTest, ItRemovesAtdocCtorComents) {
  const std::string atdocCtorLine{
      "//  @doc:\n//  ctor\n//  @doc:\n//  Ctor\n\n"};
  input_ << atdocCtorLine;

  CtorCommentRemover ctorCommentRemover;
  ctorCommentRemover.Remove(input_, &stringWriter_);

  ASSERT_EQ(emptyLine_, stringWriter_.Str());
}

TEST_F(CtorCommentRemoverTest, ItKeepsAtdocNotFollowedByCtor) {
  const std::string atdocOtherLine{"//  @doc:\nint i;\n"};
  input_ << atdocOtherLine;

  CtorCommentRemover ctorCommentRemover;
  ctorCommentRemover.Remove(input_, &stringWriter_);

  ASSERT_EQ(atdocOtherLine, stringWriter_.Str());
}
