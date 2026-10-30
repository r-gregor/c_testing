#! /bin/env bash


echo "[INFO ] - Building japan ..."

# set -xe
gcc -ggdb -Wall -o bin/japan japan.c -lm


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully built japan.c into ./build/japan!"
else
	echo "[ERROR] - Building ./build/japan failed!"
fi

echo "[INFO ] - Running ./build/japan ..."
./build/japan


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully created \"imgs/japan.png\""
else
	echo "[ERROR] - Running ./build/japan failed!"
fi
