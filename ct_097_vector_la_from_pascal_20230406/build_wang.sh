#! /bin/env bash


echo "[INFO ] - Building wang ..."

# set -xe
gcc -ggdb -Wall -o bin/wang wang.c -lm


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully built wang.c into bin/wang!"
else
	echo "[ERROR] - Building bin/wang failed!"
fi

