#! /usr/bin/env bash
# fname: just-build-all-c-files.sh
# 20260827 v1
# ---

if [ ! -d './build/' ]; then
	mkdir -v ./bin
fi

readarray -t APPS < <(ls *.c)

for APP in "${APPS[@]}"; do
	APPNAME="${APP%.*}"
	gcc -o ./build/${APPNAME} ${APP}
done

tree ./bin
