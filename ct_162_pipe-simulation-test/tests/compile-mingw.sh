#! /usr/bin/env bash
# fname: compile-mingw.sh
# v1_[]
# ---


CC=/c/Users/gregor.redelonghi/majstaf_en/majprogs_en/mingw64/bin/x86_64-w64-mingw32-gcc-11.1.0.exe
${CC} -Wall -Wextra -o ./bin/test-compiled-with-mingw chec-system.c
