#! /usr/bin/env bash
# make_random_test_moviedir.sh
# 20240423_01_en


function mkmvdr() {
	MVD="Movie $((0 + RANDOM % 9))$((0 + RANDOM % 9)) ($((2000 + RANDOM % 24)))"

	# test
	# echo "mkdir -pv \"${MVD}\""

	mkdir -pv "${MVD}"
}

# action !
mkmvdr

# ↪  for N in $(seq 1 10); do mkmvdr; done
# Movie 30 (2004)
# Movie 10 (2004)
# Movie 36 (2017)
# Movie 23 (2005)
# Movie 50 (2012)
# Movie 01 (2002)
# Movie 72 (2012)
# Movie 56 (2009)
# Movie 44 (2000)
# Movie 82 (2004)

