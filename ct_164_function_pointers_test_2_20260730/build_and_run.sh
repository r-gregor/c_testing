#! /usr/bin/env bash
# fname: build_and_run.sh
# v1_[]
# ---

if [ ! -d ./build  ]; then
	mkdir -v ./build 
fi

appname="function_pointer_test_2.c"

gcc -o ./build/${appname%.*} ${appname} && ./build/${appname%.*}

