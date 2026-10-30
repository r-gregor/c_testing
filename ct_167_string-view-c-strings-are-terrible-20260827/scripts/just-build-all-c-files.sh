#! /usr/bin/env bash
# fname: just-build-all-c-files.sh
# 20260827 v1
# ---

if [ ! -d './build/' ]; then
	mkdir -v ./build 
fi

if [ ! -d './src' ]; then
	readarray -t APPS < <(ls ./*.c)
else
	readarray -t APPS < <(ls ./src/*.c)
fi

for APP in "${APPS[@]}"; do
	APPNAMEFULL="${APP##*/}"
 	APPNAME="${APPNAMEFULL%.*}"
	gcc -o ./build/${APPNAME} ${APP}
done

tree ./build 
