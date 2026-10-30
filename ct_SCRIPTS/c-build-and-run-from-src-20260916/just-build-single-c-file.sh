#! /usr/bin/env bash
# fname: just-build-single-c-file.sh
# 20260827 v1
# ---

if [ ! -d './build/' ]; then
	mkdir -v ./build 
fi

if [ $# -ne 1 ]; then
	printf "[ERROR] no *.c file selected\n"
	exit
else
	APP="${1}"
	APPNAMEFULL="${APP##*/}"
 	APPNAME="${APPNAMEFULL%.*}"
fi

if [ ! -f "${APP}" ]; then
	printf "[ERROR] no such file: %s\n" "${APP}"
	exit
fi

gcc -o ./build/${APPNAME} ${APP}
tree ./build 

