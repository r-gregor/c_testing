#! /usr/bin/env bash
# filename: clearbuild.sh
# descpt: clean './build' directory in c-project
# 20261111 v1
# last: 20261111
# ---

printf "[i] clening ./build directory ... "
rm ./build/* >/dev/null
printf "done\n\n"

