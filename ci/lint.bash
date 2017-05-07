#!/bin/bash

set -e -x -u -o pipefail

_main() {
    clang_format
    cpplint
}

cpplint() {
    vendor/google_styleguide/cpplint/cpplint.py --extensions=cc,h orca_tidy/*
}

clang_format() {
    : ${CLANG_FORMAT:=clang-format}
    git ls-files ':!vendor' ':!.*' '*.cc' '*.h' | xargs "${CLANG_FORMAT}" -i
    git diff-files --exit-code
}

_main "$@"
