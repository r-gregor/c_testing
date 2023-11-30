#include <tchar.h>
#include "BinaryRecursion.h"
#include "LinearRecursion.h"
#include "MutualRecursion.h"
#include "NestedRecursion.h"
#include "TailRecursion.h"


int _tmain(int argc,_TCHAR argv[] )
{
	// Binary Recursion
	int result = FibNum(10);
	int result2 = FibNumLoop(10);

	printf("FibNum(10) = %d\n",result);
	printf("FibNumLoop(10) = %d\n",result2);


	// Linear Recursion
	result = Fact(10);
	result2 = FactLoop(10);

	printf("Fact(10) = %d\n",result);
	printf("FactLoop(10) = %d\n",result2);


	// Tail Recursion
	result = FibNum2(10,5,4);
	result2 = FibNum2Loop(10,5,4);

	printf("FibNum2(10,5,4) = %d\n",result);
	printf("FibNumLoop2(10,5,4) = %d\n",result2);


	// Mutual Recursion
	bool bResult = IsOddNumber(10);
	bool bResult2 = IsOddNumberLoop(10);

	bool bResult3 = IsEvenNumber(10);
	bool bResult4 = IsEvenNumberLoop(10);

	printf("IsOddNumber(10) = %d\n",(int)bResult);
	printf("IsOddNumberLoop(10) = %d\n",(int)bResult2);
	printf("IsEvenNumber(10) = %d\n",(int)bResult3);
	printf("IsEvenNumberLoop(10) = %d\n",(int)bResult4);


	// Nested Recursion
	result = Ackermann(3,2);
	result2 = AckermannLoop(3,2);

	printf("Ackermann(3,2) = %d\n",result);
	printf("AckermannLoop(3,2) = %d\n",result2);

	while(1){}
	return 0;
}