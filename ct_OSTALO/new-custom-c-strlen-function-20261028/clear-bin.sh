#! /usr/bin/env bash
# fname: clear-bin.sh
# descpt: clear './bin' directory
# 20261030 v1
# last: 20261030
# ---

SRCDIR="$(dirname "$(realpath "${BASH_SOURCE[0]}")")"

if [ ! -d "${SCRDIR}/bin" ]; then
	printf "[e] no such directory: '%s'\n\n" './bin'
	exit 1
fi

printf "[!] clearing ./bin ... "
rm -r "${SCRDIR}/bin"/* >/dev/null 2>&1
printf " done\n\n"

