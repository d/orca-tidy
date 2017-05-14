FROM ubuntu:trusty
ADD llvm-snapshot-trusty.list /etc/apt/sources.list.d/
ADD http://apt.llvm.org/llvm-snapshot.gpg.key /etc/apt/
RUN apt-key add /etc/apt/llvm-snapshot.gpg.key

RUN apt-get update -y
RUN apt-get install -y clang-format-5.0 clang-tidy-5.0
RUN apt-get install -y git
ENV CLANG_FORMAT clang-format-5.0
ENV CLANG_TIDY clang-tidy-5.0
