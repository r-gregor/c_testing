#! /usr/bin/env bash

set -xe

gcc -g -Wall -Werror -std=c11 -pedantic -o trie trie.c

./trie > trie.dot
dot -Tsvg trie.dot > trie.svg

