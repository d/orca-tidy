// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include <string>

#include "orca_tidy/string_writer.h"

void StringWriter::WriteLine(const std::string& s) {
  str_.append(s).append(1, '\n');
}

const std::string& StringWriter::Str() const { return str_; }
