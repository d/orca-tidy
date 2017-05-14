// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include "orca_tidy/temp_file_writer.h"
#include <unistd.h>
#include <array>
#include <cstdio>

TempFileWriter::TempFileWriter() {
  std::array<char, L_tmpnam> tempNameBuf{P_tmpdir "orca_tidyXXXXXX"};
  int fd = mkstemp(tempNameBuf.data());

  tempFilename_.assign(tempNameBuf.data());
  file_ = fdopen(fd, "w+");
}

void TempFileWriter::WriteLine(const std::string& line) {
  fprintf(file_, "%s\n", line.c_str());
}

const std::string& TempFileWriter::TempFilename() const {
  return tempFilename_;
}

TempFileWriter::~TempFileWriter() { fclose(file_); }
