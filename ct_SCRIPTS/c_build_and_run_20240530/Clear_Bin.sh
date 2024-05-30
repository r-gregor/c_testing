#! /usr/bin/env bash
# Clear_Bin.sh
# 20240530
# ---

if [ ${PWD##*/} = "src" ];then
	bindir="../bin"
else
	bindir="./bin"
fi

if [ ! -d ${bindir} ]; then
	echo -e "---\n[INFO] No '${bindir}' directory found!"
else
	echo -e "---\n[INFO] Removing '${bindir}' ..."
	rm -rv ${bindir}
fi

