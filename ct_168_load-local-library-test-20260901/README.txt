20260901: include-local-library-test

Compile with local header file ./src/mylibrary.h included as system header:
    #include <mylibrary.h>

In build-and-run.sh:

    CNAME=main-program-name.c     // main-program-name.c
    BNAME=${CNAME%.*}             // main-program-name

    gcc -o ./bin/${BNAME} ./src/${CNAME} -I ./src && ./bin/${BNAME}
                                         ^^^^^^^^
    ... translates to:

    gcc -o ./bin/main-program-name ./src/main-program-name.c -I ./src && ./bin/main-program-name


---

