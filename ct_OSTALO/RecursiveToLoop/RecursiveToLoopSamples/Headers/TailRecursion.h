/*! 
@file TailRecursion.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
@date July 11, 2012
@brief Tail Recursion to Loop example
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

Tail Recursion to Loop version example.

@section REFERENCE

http://www.dreamincode.net/forums/topic/51296-types-of-recursion/

*/
#ifndef __TAIL_RECURSION_H__
#define __TAIL_RECURSION_H__

#include <stack>
using namespace std;

// In this Tail Recursion example, since there is no operation after the recursive call, 
//   and there is only one recursive call, "Stage" is not required here
int FibNum2(int n, int x, int y)
{   
	if (1 == n)	
	{
		return y;
	}
	else	
	{
		return FibNum2(n-1, y, x+y);
	}
}

int FibNum2Loop(int n, int x, int y)
{
	// (First rule)
	struct SnapShotStruct // this can be declared as local structure
		//   since it will be only used within this function.
	{
		int inputN;    // parameter that changes
		int inputX;    // parameter that changes
		int inputY;    // parameter that changes
		// no local variable
	};

	// (Second rule)
	int returnVal;    // the return value at the point

	// (Third rule)
	stack<SnapShotStruct> snapshotStack;

	// (Fourth rule)
	SnapShotStruct currentSnapshot;
	currentSnapshot.inputN = n;
	currentSnapshot.inputX = x;
	currentSnapshot.inputY = y;

	snapshotStack.push(currentSnapshot);

	// (Fifth rule)
	while(!snapshotStack.empty())
	{
		currentSnapshot=snapshotStack.top();
		snapshotStack.pop();

		if(currentSnapshot.inputN == 1)
		{
			// (Eighth rule && Ninth rule)
			returnVal = currentSnapshot.inputY;
			continue;
		}
		else
		{
			// (Tenth rule)

			// Create a new snapshot for calling itself
			SnapShotStruct newSnapshot;
			newSnapshot.inputN= currentSnapshot.inputN -1 ; // give parameter as parameter given 
			                                                //   when calling itself ( FibNum(n-1, y, x+y) )
			newSnapshot.inputX= currentSnapshot.inputY;     // give parameter as parameter given when 
			                                                //   calling itself ( FibNum(n-1, y, x+y) )
			newSnapshot.inputY= currentSnapshot.inputX + currentSnapshot.inputY;// give parameter as parameter given when 
			                                                                    //   calling itself ( FibNum(n-1,y,x+y) )
			snapshotStack.push(newSnapshot);
			continue;
		}
	}
	// (Second rule)
	return returnVal;
} 

#endif //__TAIL_RECURSION_H__