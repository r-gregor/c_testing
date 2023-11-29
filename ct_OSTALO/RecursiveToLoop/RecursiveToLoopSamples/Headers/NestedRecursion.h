/*! 
@file NestedRecursion.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
@date July 11, 2012
@brief Nested Recursion to Loop example
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

Nested Recursion to Loop version example.

@section REFERENCE

http://www.dreamincode.net/forums/topic/51296-types-of-recursion/

*/
#ifndef __NESTED_RECURSION_H__
#define __NESTED_RECURSION_H__
#include <stack>
using namespace std;

int Ackermann(int x, int y)
{
	// Base or Termination Condition
	if (0 == x)
	{
		return y + 1;
	}   
	// Error Handling condition
	if (x < 0  ||  y < 0)
	{
		return -1;
	}  
	// Recursive call by Linear method 
	else if (x > 0 && 0 == y) 
	{
		return Ackermann(x-1, 1);
	}
	// Recursive call by Nested method
	else
	{
		// int midVal = Ackermann(x, y-1);
		// return Ackermann(x-1, midVal);
		return Ackermann(x-1, Ackermann(x, y-1));
	}
}



int AckermannLoop(int x, int y)
{
	// (First rule)
	struct SnapShotStruct // this can be declared as local structure 
		                  //   since it will be only used within this function.
	{
		int inputX;       // parameter that changes
		int inputY;       // parameter that changes
		int stage;
		                  // no local variable
	};

	// (Second rule)
	int returnVal;        // the return value at the point

	// (Third rule)
	stack<SnapShotStruct> snapshotStack;

	// (Fourth rule)
	SnapShotStruct currentSnapshot;
	currentSnapshot.inputX = x;
	currentSnapshot.inputY = y;
	currentSnapshot.stage = 0;

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
		case 0:
			// Base or Termination Condition
			if(currentSnapshot.inputX == 0)
			{
				// (Eighth rule && Ninth rule)
				returnVal = currentSnapshot.inputY + 1;
				continue;             // Since the function should return here
			}
			// Error Handling condition			
			if (currentSnapshot.inputX < 0  ||  currentSnapshot.inputY < 0)
			{
				// (Eighth rule && Ninth rule)
				returnVal = -1;
				continue;             // Since the function should return here
			}  
			// Recursive call by Linear method 
			else if (currentSnapshot.inputX > 0 && 0 == currentSnapshot.inputY) 
			{
				// (Tenth rule)

				// Create a new snapshot for calling itself
				SnapShotStruct newSnapshot;
				newSnapshot.inputX= currentSnapshot.inputX - 1; // give parameter as parameter given 
																//   when calling itself ( Ackermann(x-1, 1) )
				newSnapshot.inputY= 1;                          // give parameter as parameter given 
																//   when calling itself ( Ackermann(x-1, 1) )
				newSnapshot.stage= 0;
				snapshotStack.push(newSnapshot);
				continue;
			}
			// Recursive call by Nested method
			else
			{
				// (Tenth rule)

				currentSnapshot.stage=1;                        // current snapshot is done processing 
																//   and only waiting for result of calling 
																//   itself, so becomes stage "1"
				snapshotStack.push(currentSnapshot);

				// Create a new snapshot for calling itself
				SnapShotStruct newSnapshot;
				newSnapshot.inputX= currentSnapshot.inputX;	    // give parameter as parameter given 
																//   when calling itself ( Ackermann(x, y-1) )
				newSnapshot.inputY= currentSnapshot.inputY - 1; // give parameter as parameter given 
																//   when calling itself ( Ackermann(x, y-1) )
				newSnapshot.stage = 0;
				snapshotStack.push(newSnapshot);
				continue;
			}
			break;
		case 1:
			// (Tenth rule)

			// Create a new snapshot for calling itself
			SnapShotStruct newSnapshot;
			newSnapshot.inputX= currentSnapshot.inputX - 1;   // give parameter as parameter given 
															  //   when calling itself ( Ackermann(x-1,  Ackermann(x, y-1)) )
			newSnapshot.inputY= returnVal;                    // give parameter as parameter given 
															  //   when calling itself ( Ackermann(x-1,  Ackermann(x, y-1)) )
			newSnapshot.stage = 0;
			snapshotStack.push(newSnapshot);
			continue;
			break;
		}
	}
	// (Second rule)
	return returnVal;
}     
#endif //__NESTED_RECURSION_H__