// Copyright (c) Jesse Zhang

#include <fstream>
#include "orca_tidy/Rewriter.h"

Rewriter::Rewriter(const std::string fileName, TidierInterface& tidier)
    : fileName_(fileName), tidier_(tidier) {}

void Rewriter::Rewrite() {
  std::ifstream input{fileName_};
  int tempfd = mkstemp("/tmp/yolo.XXXXXX");
}
