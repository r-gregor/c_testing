#! /usr/bin/env bash
# Clear_Bin.sh
# 20240530
# ---

if [ ${PWD##*/} = "src" ];then
	bindir="../build "
else
	bindir="./build "
fi

if [ ! -d ${bindir} ]; then
	echo -e "---\n[INFO] No '${bindir}' directory found!"
else
	echo -e "---\n[INFO] Removing '${bindir}' ..."
	rm -rv ${bindir}
fi

