// Copyright (c) 2017 Jesse Zhang All rights reserved.

#ifndef ORCA_TIDY_TEMP_FILE_WRITER_H_
#define ORCA_TIDY_TEMP_FILE_WRITER_H_

#include <cstdio>
#include <fstream>
#include <string>
#include "orca_tidy/writer.h"

class TempFileWriter : public Writer {
 private:
  std::string tempFilename_;
  FILE* file_;

 public:
  virtual ~TempFileWriter();
  TempFileWriter();
  void WriteLine(const std::string& line) override;
  const std::string& TempFilename() const;
};

#endif  // ORCA_TIDY_TEMP_FILE_WRITER_H_
