#! /usr/bin/env bash
# fname: build.sh
# 20260915 v1
# ---

for CCC in *.c; do gcc -o "${CCC%.*}" "${CCC}"; done

