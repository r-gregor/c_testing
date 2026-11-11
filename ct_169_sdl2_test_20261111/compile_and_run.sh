#! /usr/bin/env bash
# srcf_path: build_only
# descpt: 
# 20261111 v1
# last: 20261111
# ---


if [ $# -ne 1 ]; then
	printf "[e] must suply /src/*.c file\n\n"
	exit 1
else
	srcf_path="$1"
fi

if [ ! -f "${srcf_path}" ]; then
	printf "[e] no such file: '%s'\n\n" "${srcf_path}"
	exit 2
fi

srcf="${srcf_path##*/}"
target="${srcf%.*}"
printf "[?] compiling: '%s' into '%s' ... " "./src/${srcf}" "./build/${target}" 
read -r -p "OK?"

printf "[i] running: '%s' ... \n" "./build/${target}"
gcc -Wall -o "./build/${target}" "./src/${srcf}" -I"/usr/include/SDL2" -lSDL2 && "./build/${target}"

printf "\n"
