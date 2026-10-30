#! /bin/env bash


echo "[INFO ] - Building main ..."

# set -xe
gcc -ggdb -Wall -o bin/main main.c -lm


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully built main.c into ./build/main!"
else
	echo "[ERROR] - Building ./build/main failed!"
fi

echo "[INFO ] - Running ./build/main ..."
./build/main


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully created \"imgs/output.png\""
else
	echo "[ERROR] - Running ./build/main failed!"
fi
