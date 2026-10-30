#! /usr/bin/env bash

executable="./build/memory_management_testing_v1"
# /usr/bin/valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ${executable}
/usr/bin/valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s "$@"

