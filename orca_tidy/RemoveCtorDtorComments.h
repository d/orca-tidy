// Copyright (C) 2017 Pivotal Software, Inc.

#ifndef ORCA_TIDY_REMOVECTORDTORCOMMENTS_H_
#define ORCA_TIDY_REMOVECTORDTORCOMMENTS_H_

#include <iosfwd>
#include <sstream>

class RemoveCtorDtorComments {
  std::istream& input_;
  std::ostream& output_;

 public:
  RemoveCtorDtorComments(std::istringstream& input, std::ostringstream& output);
  void tidy();
};

#endif  // ORCA_TIDY_REMOVECTORDTORCOMMENTS_H_
