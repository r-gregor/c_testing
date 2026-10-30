#! /usr/bin/env bash
# fname: build-and-run.sh
# 20260901 v1
# ---

if [ ! -d ./bin ]; then
	mkdir -v ./bin
fi

CNAME=include-local-library-test.c
BNAME=${CNAME%.*}

gcc -o ./build/${BNAME} ./src/${CNAME} -I ./src

