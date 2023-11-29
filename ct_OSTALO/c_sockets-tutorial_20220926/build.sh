for FFF in src/*.c; do gcc -g -Wall -o bin/$(basename ${FFF//.c/}) $FFF; done
