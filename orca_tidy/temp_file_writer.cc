// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include "orca_tidy/temp_file_writer.h"
#include <array>
#include <cstdio>

TempFileWriter::TempFileWriter() {
  std::array<char, L_tmpnam> tempNameBuf{};
  std::tmpnam(tempNameBuf.data());

  tempFilename_.assign(tempNameBuf.data());
  ofile_.open(tempFilename_);
}

void TempFileWriter::WriteLine(const std::string& line) {
  ofile_ << line << '\n';
}

const std::string& TempFileWriter::TempFilename() const {
  return tempFilename_;
}
