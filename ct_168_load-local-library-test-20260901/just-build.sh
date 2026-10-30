#! /usr/bin/env bash
# fname: build-and-run.sh
# 20260901 v1
# ---

if [ ! -d ./build  ]; then
	mkdir -v ./build 
fi

CNAME=include-local-library-test.c
BNAME=${CNAME%.*}

gcc -o ./build/${BNAME} ./src/${CNAME} -I ./src

