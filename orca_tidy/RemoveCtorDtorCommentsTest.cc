// Copyright (C) 2017 Jesse Zhang

#include "orca_tidy/RemoveCtorDtorComments.h"

#include "gtest/gtest.h"

TEST(RemoveCtorDtorCommentsTest, ItRemovesAtDocCtorComments) {
  std::string bad_input =
      "//   @doc:\n"
      "//           Ctor\n";
  std::istringstream bad_input_stream(bad_input);
  std::ostringstream output_stream;
  RemoveCtorDtorComments tidier{};
  tidier.Tidy(bad_input_stream, output_stream);

  ASSERT_EQ(std::string(), output_stream.str());
}

TEST(RemoveCtorDtorCommentsTest, ItDoesNotRemoveOtherLines) {
  std::string good_input =
      "   @doc:\n"
      "           function that eats spaghetti\n";
  std::istringstream good_input_stream(good_input);
  std::ostringstream output_stream;
  RemoveCtorDtorComments tidier{};
  tidier.Tidy(good_input_stream, output_stream);

  ASSERT_EQ(good_input, output_stream.str());
}
