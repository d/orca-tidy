// Copyright (c) 2017 Jesse Zhang All rights reserved.

#ifndef ORCA_TIDY_REWRITER_H_
#define ORCA_TIDY_REWRITER_H_

#include <string>

#include "orca_tidy/ctor_comment_remover.h"

class Rewriter {
 private:
  std::string filename_;
  CtorCommentRemover* const ctorCommentRemover_;

 public:
  explicit Rewriter(std::string filename,
                    CtorCommentRemover* ctorCommentRemover);
  void Rewrite();
};

#endif  // ORCA_TIDY_REWRITER_H_
