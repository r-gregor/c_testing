#! /usr/bin/env bash

# rgregor@muadib ~/_c_d_testing

for NNN in 097 098 099 100; do diff -q cd${NNN}*/ ~/OLDHDD/Dropbox/ODPRTO/MCDN_en/coding/C_Cpp_en/c_en_testing/cn${NNN}*/; done | grep --color Only

