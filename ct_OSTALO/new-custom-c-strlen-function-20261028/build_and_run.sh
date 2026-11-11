#! /usr/bin/env bash
# fname: build_and_run.sh
# descpt: 
# 20261028 v1
# last: 20261028
# ---

if [ ! -d ./bin ]; then
	printf "[!] no './bin' directory\n"
	printf "[i] creating './bin' directory\n"
	mkdir -pv ./bin
fi

if [ ! -d ./src ]; then
	printf "[!] no './src' directory\n"
	printf "[i] creating './scr' directory\n"
	mkdir -pv ./src
	printf "[i] moving '*.s' and '*.h' files into './scr' directory\n"
	mv -v ./*.c ./*.h ./src
fi

gcc -Wall -o ./bin/new-custom-c-strlen-function ./src/new-custom-c-strlen-function.c && ./bin/new-custom-c-strlen-function

