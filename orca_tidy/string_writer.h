// Copyright (c) 2017 Jesse Zhang All rights reserved.

#ifndef ORCA_TIDY_STRING_WRITER_H_
#define ORCA_TIDY_STRING_WRITER_H_

#include <string>
#include "orca_tidy/writer.h"

class StringWriter : public Writer {
 private:
  std::string str_;

 public:
  void WriteLine(const std::string& s) override;
  const std::string& Str() const;
};

#endif  // ORCA_TIDY_STRING_WRITER_H_
