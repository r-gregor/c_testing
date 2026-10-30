#! /usr/bin/env bash
# fname: clear-bin.sh
# 20260826 v1
# ---

if [ ! -d './build/' ]; then
	exit
fi

rm -rv ./build/*

