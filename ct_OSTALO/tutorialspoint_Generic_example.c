#include <stdio.h>
#define typecheck(T) _Generic( (T), \
					char: "Char", \
					int: "Int", \
					long: "Long", \
					float: "Float", \
					default: NULL)

int main(void) {
   printf( "passing a long value to the macro, result is: \"%s\" \n", typecheck(2353463456356465));
   printf( "passing a float value to the macro, result is: \"%s\" \n", typecheck(4.32f));
   printf( "passing a int value to the macro, result is: \"%s\" \n", typecheck(324));
   printf( "passing a string value to the macro, result is: \"%s\" \n", typecheck("Hello"));
   return 0;
}

