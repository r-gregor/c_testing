#! /usr/bin/env bash
# fname: local-test.sh
# descpt: 
# 20261028 v1
# last: 20261028
# ---

num=0

# === FUNCTIONS ===
calculate() {
	local end=10
	while [ $end -gt 0 ]; do
		((num++))
		((end--))
	done
}

# === MAIN ===
printf "num before function call: '%d'\n" $num
calculate
printf "num after  function call: '%d'\n" $num
printf "\n"

