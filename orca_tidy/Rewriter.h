// Copyright (c) Jesse Zhang

#ifndef ORCA_TIDY_REWRITER_H_
#define ORCA_TIDY_REWRITER_H_

#include <string>
#include "TidierInterface.h"
class Rewriter {
 private:
  const std::string fileName_;
  TidierInterface& tidier_;

 public:
  Rewriter(const std::string fileName, TidierInterface& tidier);
  void Rewrite();
};

#endif  // ORCA_TIDY_REWRITER_H_
