#! /usr/bin/env bash
# fname: clear-bin.sh
# 20260901 v1
# ---

if [ ! -d ./bin ]; then
	printf "\n"
	exit
fi


rm -rv ./bin/*
