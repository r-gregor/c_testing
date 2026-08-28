#! /usr/bin/env bash
# fname: just-build-single-c-file.sh
# 20260827 v1
# ---

if [ ! -d './bin/' ]; then
	mkdir -v ./bin
fi

if [ $# -ne 1 ]; then
	printf "[ERROR] no *.c file selected\n"
	exit
else
	APP="${1}"
	APPNAME="${APP%.*}"
fi

if [ ! -f "${APP}" ]; then
	printf "[ERROR] no such file: %s\n" "${APP}"
	exit
fi

gcc -o ./bin/${APPNAME} ${APP}
tree ./bin

