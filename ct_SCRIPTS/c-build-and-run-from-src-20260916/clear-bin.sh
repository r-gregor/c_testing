#! /usr/bin/env bash
# fname: clear-bin.sh
# 20260826 v1
# ---

if [ ! -d './bin/' ]; then
	exit
fi

rm -rv ./bin/*

