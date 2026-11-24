#! /usr/bin/env bash

if [ $# -eq 1 ]; then
	fname=$1
else
	echo "Must supply [filename].c to compile"
	exit
fi

if [ ! -f ${fname} ]; then
	echo "File ${fname} does NOT exist!"
	exit
fi

if [ ! -d ./build  ]; then
	echo "No './build directory. Creating one ..."
	mkdir ./build
<<<<<<< HEAD
=======
:wq
>>>>>>> 644dab4 (update 20261124_1828_jbe)
fi

fname_base=${fname//.c/}

# set -xe

# compile
gcc -Wall -Wextra -o ./build/${fname_base} ${fname}
<<<<<<< HEAD
# clang -Wall -Wextra -Werror -o bin/${fname_base} ${fname}
# clang -Wall -Wextra -o bin/${fname_base} ${fname}
=======
# clang -Wall -Wextra -Werror -o ./build/${fname_base} ${fname}
# clang -Wall -Wextra -o ./build/${fname_base} ${fname}
>>>>>>> 644dab4 (update 20261124_1828_jbe)

# run
echo "OUTPUT:"
./build/${fname_base}

