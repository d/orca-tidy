// Copyright (c) 2017 Jesse Zhang All rights reserved.

#include "orca_tidy/ctor_comment_remover.h"

#include <string>
#include <utility>
#include "re2/re2.h"

CtorCommentRemover::CtorCommentRemover() {}

void CtorCommentRemover::Remove(std::istream& ifile, Writer* writer) const {
  std::string line;
  std::string stash;
  const re2::RE2 atdoc("//\\s+@doc:");
  const re2::RE2 ctor("//\\s+(C|c)tor");
  while (std::getline(ifile, line)) {
    if (re2::RE2::FullMatch(line, atdoc)) {
      stash = std::move(line);
    } else if (re2::RE2::FullMatch(line, ctor)) {
      stash.erase();
      continue;
    } else {
      if (!stash.empty()) {
        writer->WriteLine(stash);
        stash.erase();
      }
      writer->WriteLine(line);
    }
  }
}
