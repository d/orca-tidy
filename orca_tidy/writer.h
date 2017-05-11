// Copyright (c) 2017 Jesse Zhang All rights reserved.

#ifndef ORCA_TIDY_WRITER_H_
#define ORCA_TIDY_WRITER_H_

#include <string>

class Writer {
 public:
  virtual ~Writer();
  virtual void WriteLine(const std::string& s) = 0;
};

#endif  // ORCA_TIDY_WRITER_H_
