// Copyright (C) 2017 Jesse Zhang

#ifndef ORCA_TIDY_TIDIERINTERFACE_H_
#define ORCA_TIDY_TIDIERINTERFACE_H_

#include <iosfwd>

class TidierInterface {
 public:
  virtual void Tidy(std::istream& input, std::ostream& output) = 0;
  virtual ~TidierInterface();
};

#endif  // ORCA_TIDY_TIDIERINTERFACE_H_
