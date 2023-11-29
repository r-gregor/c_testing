/*! 
@file MutualRecursion.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
@date July 11, 2012
@brief Mutual Recursion to Loop example
@version 1.0

@section LICENSE

The MIT License (MIT)

Copyright (c) 2008-2013 Woong Gyu La <juhgiyo@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

@section DESCRIPTION

Mutual Recursion to Loop version example.

@section REFERENCE

http://www.dreamincode.net/forums/topic/51296-types-of-recursion/

*/
#ifndef __MUTUAL_RECURSION_H__
#define __MUTUAL_RECURSION_H__
#include <stack>
using namespace std;

bool IsEvenNumber(int n);
bool IsOddNumber(int n);
bool isOddOrEven(int n, int stage);

bool IsOddNumber(int n)
{
	// Base or Termination Condition
	if (0 == n)
		return false;
	else
		// Recursive call by Mutual Method
		return IsEvenNumber(n - 1);
}

bool IsEvenNumber(int n)
{
	// Base or Termination Condition
	if (0 == n)
		return true;
	else
		// Recursive call by Mutual Method
		return IsOddNumber(n - 1);
} 



bool IsOddNumberLoop(int n)
{
	return isOddOrEven(n , 0);
}

bool IsEvenNumberLoop(int n)
{
	return isOddOrEven(n , 1);
}

bool isOddOrEven(int n, int stage)
{
	// (First rule)
	struct SnapShotStruct // this can be declared as local structure 
		                  //   since it will be only used within this function.
	{
		int inputN;       // parameter that changes
		int stage;
		                  // no local variable
	};

	// (Second rule)
	bool returnVal;       // the return value at the point

	// (Third rule)
	stack<SnapShotStruct> snapshotStack;

	// (Fourth rule)
	SnapShotStruct currentSnapshot;
	currentSnapshot.inputN = n;
	currentSnapshot.stage = stage;

	snapshotStack.push(currentSnapshot);

	// (Fifth rule)
	while(!snapshotStack.empty())
	{
		currentSnapshot=snapshotStack.top();
		snapshotStack.pop();

		// (Sixth rule)
		switch(currentSnapshot.stage)
		{
			// (Seventh rule)
			// bool IsOddNumber(int n)
		case 0:
			// Base or Termination Condition
			if (0 == currentSnapshot.inputN)
			{
				// (Eighth rule && Ninth rule)
				returnVal = false;
				continue;
			}
			else
			{
				// (Tenth rule)

				// Recursive call by Mutual Method

				// Create a new snapshot for calling itself
				SnapShotStruct newSnapshot;
				newSnapshot.inputN= currentSnapshot.inputN - 1; // give parameter as parameter given 
				//   when calling itself ( IsEvenNumber(n - 1) )
				newSnapshot.stage= 1;
				snapshotStack.push(newSnapshot);
				continue;
			}

			break;
			// (Seventh rule)
			// bool IsEvenNumber(int n)
		case 1:
			// Base or Termination Condition
			if (0 == currentSnapshot.inputN)
			{
				// (Eighth rule && Ninth rule)
				returnVal = true;
				continue;
			}
			else
			{
				// (Tenth rule)

				// Recursive call by Mutual Method

				// Create a new snapshot for calling itself
				SnapShotStruct newSnapshot;
				newSnapshot.inputN= currentSnapshot.inputN - 1; // give parameter as parameter given 
				//   when calling itself ( IsEvenNumber(n - 1) )
				newSnapshot.stage= 0;
				snapshotStack.push(newSnapshot);
				continue;
			}
			break;
		}

	}
	// (Second rule)
	return returnVal;
}  

#endif //__MUTUAL_RECURSION_H__