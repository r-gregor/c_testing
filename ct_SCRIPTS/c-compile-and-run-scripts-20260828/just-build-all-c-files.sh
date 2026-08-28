#! /usr/bin/env bash
# fname: just-build-all-c-files.sh
# 20260827 v1
# ---

if [ ! -d './bin/' ]; then
	mkdir -v ./bin
fi

readarray -t APPS < <(ls *.c)

for APP in "${APPS[@]}"; do
	APPNAME="${APP%.*}"
	gcc -o ./bin/${APPNAME} ${APP}
done

tree ./bin
