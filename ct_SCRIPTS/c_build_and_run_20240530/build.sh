#! /usr/bin/env bash
# build.sh
# 20240530
# MAIN -> filename with entry point! Does NOT have to be "main"
# ---

CC="gcc"
CFLAGS="-Wall"
MAIN="main"

if [ ${PWD##*/} = "src" ];then
	bindir="../bin"
else
	bindir="./bin"
fi


if [ ! -d ${bindir} ]; then
	echo -e "---\n[INFO] No '${bindir}' directory found ... creating one"
	mkdir -v ${bindir}
fi

for nm in $(ls -1 *.c); do
	# nmb=${nm%%.*}
	CFILES="${CFILES} ${nm}"
done

echo -e "---\n[INFO] Building '${nm}' ..."
${CC} ${CFLAGS} -o ${bindir}/${MAIN} ${CFILES}

if [ $? -eq 0 ]; then
	echo -e "[INFO] Build successful\n---"
else
	echo -e "---\n[INFO] Build NOT successful."
fi

