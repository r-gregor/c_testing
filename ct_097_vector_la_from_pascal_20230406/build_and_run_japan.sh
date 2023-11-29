#! /bin/env bash


echo "[INFO ] - Building japan ..."

# set -xe
gcc -ggdb -Wall -o bin/japan japan.c -lm


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully built japan.c into ./bin/japan!"
else
	echo "[ERROR] - Building ./bin/japan failed!"
fi

echo "[INFO ] - Running ./bin/japan ..."
./bin/japan


if [ $? -eq 0 ]; then
	echo "[INFO ] - Succesfully created \"imgs/japan.png\""
else
	echo "[ERROR] - Running ./bin/japan failed!"
fi
