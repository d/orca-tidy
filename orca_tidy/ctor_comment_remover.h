// Copyright (c) 2017 Jesse Zhang All rights reserved.

#ifndef ORCA_TIDY_CTOR_COMMENT_REMOVER_H_
#define ORCA_TIDY_CTOR_COMMENT_REMOVER_H_

#include <fstream>
#include <memory>
#include "orca_tidy/writer.h"

class CtorCommentRemover {
 public:
  CtorCommentRemover();

  void Remove(std::istream& ifile, Writer* writer) const;
};

#endif  // ORCA_TIDY_CTOR_COMMENT_REMOVER_H_
