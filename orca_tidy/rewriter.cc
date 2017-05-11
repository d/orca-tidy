// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include <array>
#include <cstdio>
#include <fstream>
#include <memory>
#include <utility>

#include "orca_tidy/rewriter.h"
#include "orca_tidy/temp_file_writer.h"

void Rewriter::Rewrite() {
  TempFileWriter fileWriter;

  std::ifstream ifile{filename_};

  ctorCommentRemover_->Remove(ifile, &fileWriter);
  std::rename(fileWriter.TempFilename().c_str(), filename_.c_str());
}

Rewriter::Rewriter(std::string filename, CtorCommentRemover* ctorCommentRemover)
    : filename_(filename), ctorCommentRemover_(ctorCommentRemover) {}
