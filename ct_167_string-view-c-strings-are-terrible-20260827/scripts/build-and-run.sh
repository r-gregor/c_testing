#! /usr/bin/env bash
# fname: build-and-run.sh
# 20260826 v1
# ---

if [ ! -d './build/' ]; then
	mkdir -v ./build 
fi

if [ $# -ne 1 ]; then
	printf "[ERROR] no *.c file selected\n\n"
	exit
else
	APP="${1}"
	APPNAMEFULL="${APP##*/}"
 	APPNAME="${APPNAMEFULL%.*}"
fi

if [ ! -f "${APP}" ]; then
	printf "[ERROR] no such file: %s\n\n" "${APP}"
	exit
fi

gcc -o ./build/${APPNAME} ${APP} && ./build/${APPNAME}

