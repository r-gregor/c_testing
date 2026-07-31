#! /usr/bin/env bash
# fname: build_and_run.sh
# v1_[]
# ---

if [ ! -d ./bin ]; then
	mkdir -v ./bin
fi

appname="function_pointer_test_2.c"

gcc -o ./bin/${appname%.*} ${appname} && ./bin/${appname%.*}

