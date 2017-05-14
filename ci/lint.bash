#!/bin/bash

set -e -x -u -o pipefail

_main() {
    clang_format
    cpplint
    clang_tidy
}

cpplint() {
    vendor/google_styleguide/cpplint/cpplint.py --extensions=cc,h orca_tidy/*
}

our_code() {
    git ls-files ':!vendor' ':!.*' "$@"
}

clang_tidy() {
    : ${CLANG_TIDY:=/usr/local/opt/llvm/bin/clang-tidy}
    our_code '*.cc' | xargs "${CLANG_TIDY}" -p build
}

clang_format() {
    : ${CLANG_FORMAT:=clang-format}
    our_code '*.cc' '*.h' | xargs "${CLANG_FORMAT}" -i
    git diff-files --exit-code
}

_main "$@"
