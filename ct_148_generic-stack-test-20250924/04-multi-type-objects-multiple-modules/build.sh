#! /usr/bin/env bash

if [ ! -d ./bin ]; then
	echo "[INFO] no './bin' directory"
	echo -n "[INFO] "
	mkdir -v ./bin
fi

fname="multi-type-objects-modules-test-v1"

echo -n "[INFO] compiling ..."
gcc -Wall -o ./bin/${fname} *.c *.h && echo " OK"
echo ""

