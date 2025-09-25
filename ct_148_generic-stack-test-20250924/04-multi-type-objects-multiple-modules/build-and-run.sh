#! /usr/bin/env bash

ver=1

if [ ! -d ./bin ]; then
	echo "[INFO] no './bin' directory"
	echo -n "[INFO] "
	mkdir -v ./bin
fi

fname="multy-type-objects-modules-testi-v${ver}"

echo "[INFO] compiling ..."
echo "[INFO] running ..."
gcc -o ./bin/${fname} *.c *.h && ./bin/${fname}

