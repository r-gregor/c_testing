#! /bin/env bash


echo "[INFO ] - Building wang ..."

# set -xe
gcc -ggdb -Wall -o bin/wang wang.c -lm


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully built wang.c into ./build/wang!"
else
	echo "[ERROR] - Building ./build/wang failed!"
fi

echo "[INFO ] - Running ./build/wang ..."
./build/wang


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully created \"imgs/output.png\""
else
	echo "[ERROR] - Running ./build/wang failed!"
fi
