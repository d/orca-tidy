// Copyright (c) 2017 Jesse Zhang All rights reserved.

#ifndef ORCA_TIDY_TEMP_FILE_WRITER_H_
#define ORCA_TIDY_TEMP_FILE_WRITER_H_

#include <fstream>
#include <string>
#include "orca_tidy/writer.h"

class TempFileWriter : public Writer {
 private:
  std::string tempFilename_;
  std::ofstream ofile_;

 public:
  TempFileWriter();
  void WriteLine(const std::string& line) override;
  const std::string& TempFilename() const;
};

#endif  // ORCA_TIDY_TEMP_FILE_WRITER_H_
