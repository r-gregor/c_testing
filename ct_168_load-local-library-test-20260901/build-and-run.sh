#! /usr/bin/env bash
# fname: build-and-run.sh
# 20260901 v1
# ---

CNAME=include-local-library-test.c
BNAME=${CNAME%.*}

gcc -o ./bin/${BNAME} ./src/${CNAME} -I ./src && ./bin/${BNAME}

