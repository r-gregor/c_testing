#! /usr/bin/env bash

echo "Compiling ..."
gcc -Wall -o ./build/reversed ./src/reverse.c

echo -e "Running ...\n"
./build/reversed.exe


