// Copyright (C) 2017 Jesse Zhang

#include "orca_tidy/RemoveCtorDtorComments.h"
#include <regex>
#include <string>
#include <utility>
#include <vector>

void RemoveCtorDtorComments::Tidy(std::istream& input, std::ostream& output) {
  std::vector<std::string> stage;
  for (std::string line; getline(input, line);) {
    const std::regex at_doc_pattern(R"(//\s+@doc:\s*)");
    const std::regex ctor_pattern(R"(//\s+Ctor)");
    if (regex_match(line, at_doc_pattern)) {
      stage.push_back(std::move(line));
    } else if (regex_match(line, ctor_pattern)) {
      stage.clear();
    } else {
      for (const std::string& staged_line : stage) {
        output << staged_line << '\n';
      }
      stage.clear();
      output << line << '\n';
    }
  }
}

RemoveCtorDtorComments::~RemoveCtorDtorComments() {}

RemoveCtorDtorComments::RemoveCtorDtorComments() {}
