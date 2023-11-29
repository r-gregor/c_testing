/*! 
@file BinaryRecursion.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
@date July 11, 2012
@brief Binary Recursion to Loop example
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

Binary Recursion to Loop version example.

@section REFERENCE

http://www.dreamincode.net/forums/topic/51296-types-of-recursion/

*/
#ifndef __BINARY_RECURSION_H__
#define __BINARY_RECURSION_H__

#include <stack>
using namespace std;

int FibNum(int n)
{
	if (n < 1)
		return -1;
	if (1 == n || 2 == n)
		return 1;

	// think this as
	// int addVal = FibNum( n - 1);
	// addVal += FibNum(n - 2);
	// return addVal;
	return FibNum(n - 1) + FibNum(n - 2);							 
} 

int FibNumLoop(int n)
{
	// (First rule)
	struct SnapShotStruct // this can be declared as local structure 
	                      //   since it will be only used within this function.
	{
		int inputN;       // parameter that changes
		int addVal;       // the local variable that changes
		int stage;        // the stage variable to track where the snapshot has taken

	};

	// (Second rule)
	int returnVal;        // the return value at the point

	// (Third rule)
	stack<SnapShotStruct> snapshotStack;

	// (Fourth rule)
	SnapShotStruct currentSnapshot;
	currentSnapshot.inputN=n;
	currentSnapshot.stage=0; // as initial stage

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
			if(currentSnapshot.inputN<1)
			{
				// (Eighth rule && Ninth rule)
				returnVal = -1;
				continue;
			}
			if(currentSnapshot.inputN == 1 || currentSnapshot.inputN == 2 )
			{
				// (Eighth rule && Ninth rule)
				returnVal = 1;
				continue;
			}
			else
			{
				// (Tenth rule)

				// return ( FibNum(n - 1) + FibNum(n - 2)); this is actually two steps 
				//   (first calling itself with parameter n-1, and second calling itself with parameter n-2)
				//   this is where we need make a snapshot, and split into two different stages.
				currentSnapshot.stage=1;                        // current snapshot is done processing and 
				                                                //   only waiting for result of calling itself,
			                                                    //   so becomes stage "1"
				snapshotStack.push(currentSnapshot);

				// Create a new snapshot for calling itself
				SnapShotStruct newSnapshot;
				newSnapshot.inputN= currentSnapshot.inputN -1 ; // give parameter as parameter given 
				                                                //   when calling itself 
				                                                //   (first case FibNum(n - 1))
				newSnapshot.stage = 0 ;                         // since it will start from the beginning of
				                                                //   the function, give the initial stage
				snapshotStack.push(newSnapshot);
				continue;

			}
			break;
			// (Seventh rule)
		case 1:

			// (Tenth rule)

			currentSnapshot.addVal = returnVal;
			currentSnapshot.stage=2;                         // current snapshot is done processing and 
			                                                 //   only waiting for result of calling itself, 
			                                                 //   so becomes stage "2"
			snapshotStack.push(currentSnapshot);

			// Create a new snapshot for calling itself
			SnapShotStruct newSnapshot;
			newSnapshot.inputN= currentSnapshot.inputN - 2 ; // give parameter as parameter given when calling
			                                                 //   itself (first case FibNum(n - 2))
			newSnapshot.stage = 0 ;                          // since it will start from the beginning of 
			                                                 //   the function, give the initial stage
			snapshotStack.push(newSnapshot);
			continue;
			break;
		case 2:
			// (Eighth rule)
			returnVal = currentSnapshot.addVal + returnVal;  // actual addition of ( FibNum(n - 1) + FibNum(n - 2) )

			// (Ninth rule)
			continue;
			break;
		}
	}  

	// (Second rule)
	return returnVal;
}
  

#endif //__BINARY_RECURSION_H__