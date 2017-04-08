// Copyright (C) 2017 Jesse Zhang

#include "orca_tidy/RemoveCtorDtorComments.h"
#include <regex>
#include <string>
#include <utility>
#include <vector>

void RemoveCtorDtorComments::tidy() {
  std::vector<std::string> stage;
  for (std::string line; getline(input_, line);) {
    const std::regex at_doc_pattern("//\\s+@doc:\\s*");
    if (regex_match(line, at_doc_pattern)) {
      stage.push_back(std::move(line));
    } else {
      const std::regex ctor_pattern("//\\s+Ctor");
      if (regex_match(line, ctor_pattern)) {
        stage.clear();
      } else {
        for (const std::string &staged_line : stage) {
          output_ << staged_line << '\n';
        }
        stage.clear();
        output_ << line << '\n';
      }
    }
  }
}

RemoveCtorDtorComments::RemoveCtorDtorComments(std::istringstream &input,
                                               std::ostringstream &output)
    : input_(input), output_(output) {}
