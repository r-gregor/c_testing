#! /usr/bin/env bash

executable="./build/BrthReminder_c"
/usr/bin/valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ${executable}

