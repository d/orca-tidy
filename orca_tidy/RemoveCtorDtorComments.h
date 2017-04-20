// Copyright (C) 2017 Jesse Zhang

#ifndef ORCA_TIDY_REMOVECTORDTORCOMMENTS_H_
#define ORCA_TIDY_REMOVECTORDTORCOMMENTS_H_

#include <iosfwd>
#include <sstream>
#include "TidierInterface.h"

class RemoveCtorDtorComments : public TidierInterface {
 public:
  RemoveCtorDtorComments();
  void Tidy(std::istream& input, std::ostream& output) override;
  ~RemoveCtorDtorComments() override;
};

#endif  // ORCA_TIDY_REMOVECTORDTORCOMMENTS_H_
