#!/bin/bash

set -e -x -u -o pipefail

_main() {
    clang_format_version
}

clang_format_version() {
    : ${CLANG_FORMAT:=clang-format}
    "${CLANG_FORMAT}" --version
}

_main "$@"
