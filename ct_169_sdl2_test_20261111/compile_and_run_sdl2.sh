#! /usr/bin/env bash
# filename: compile_and_run_sdl2.sh
# descpt: compile *.c file using sdl2 library into './build' directory and run it
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

if [ ! -d ./build ]; then
	printf "[!] no './build' directory\n"
	printf "[?] create './build' directory (y/Y)? "
	read -r ans
	if [[ "${ans}" != 'y' && "${ans}" != 'Y' ]]; then
		printf "[e] could not compile into './build' directory\n\n"
		exit 1
	else
		printf "[!] creating './build' diractory ...\n"
		mkdir -v "./build"
	fi
fi

srcf="${srcf_path##*/}"
target="${srcf%.*}"
printf "[?] compiling: '%s' into '%s' ... " "./src/${srcf}" "./build/${target}"
read -r -p "OK?"

printf "[i] running: '%s' ... " "./build/${target}"
gcc -Wall -o "./build/${target}" "./src/${srcf}" -I"/usr/include/SDL2" -lSDL2 && "./build/${target}"
printf "done\n"

printf "\n"

