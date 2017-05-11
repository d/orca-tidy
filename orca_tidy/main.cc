// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include <memory>
#include <string>

#include "orca_tidy/ctor_comment_remover.h"
#include "orca_tidy/rewriter.h"

int main(int argc, const char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    const char* const filename = argv[i];

    CtorCommentRemover ctorCommentRemover;
    Rewriter rewriter{filename, &ctorCommentRemover};
    rewriter.Rewrite();
  }

  return 0;
}
