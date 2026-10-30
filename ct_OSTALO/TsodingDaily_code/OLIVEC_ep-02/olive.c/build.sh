#!/bin/sh

set -xe

mkdir -p ./build/
cc -Wall -Wextra -ggdb -o ./build/example example.c
cc -Wall -Wextra -ggdb -o ./build/test test.c -lm
./build/example
./build/test
