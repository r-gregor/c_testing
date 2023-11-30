/*! 
@file LinearRecursion.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
@date July 11, 2012
@brief Linear Recursion to Loop example
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

Linear Recursion to Loop version example.

@section REFERENCE

http://www.dreamincode.net/forums/topic/51296-types-of-recursion/

*/
#ifndef __LINEAR_RECURSION_H__
#define __LINEAR_RECURSION_H__

#include <stack>
using namespace std;

int Fact(long n)
{
	if(0>n)
		return -1;
	if(0 == n)
		return 1;
	else
	{
		return ( n* Fact(n-1));
	}
} 

int FactLoop(long n)
{
	// (First rule)
	struct SnapShotStruct // this can be declared as local structure 
					      //   since it will be only used within this function.
	{
		long inputN;      // parameter that changes
		                  // no local variable
		int stage;        // the stage variable to track where the snapshot has taken
	} ;

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
			if(0>currentSnapshot.inputN)
			{
				// (Eighth rule && Ninth rule)
				returnVal = -1;
				continue;
			}
			if(0 == currentSnapshot.inputN)
			{
				// (Eighth rule && Ninth rule)
				returnVal = 1;     
				continue;
			}
			else
			{
				// (Tenth rule)

				// return ( n* Fact(n-1)); this is actually two steps 
				//  (first calling itself, and second with the value returns multiply with current n value.)
				//  this is where we need make a snapshot.
				currentSnapshot.stage=1; // current snapshot is done processing and 
				                          //   only waiting for result of calling itself,
				                          //   so becomes stage "1"
				snapshotStack.push(currentSnapshot);

				// Create a new snapshot for calling itself
				SnapShotStruct newSnapshot;
				newSnapshot.inputN= currentSnapshot.inputN -1 ; // give parameter as parameter given 
				                                                 //   when calling itself.
				newSnapshot.stage = 0 ;                          // since it will start from the begining of 
				                                                 //   the function, give the initial stage
				snapshotStack.push(newSnapshot);
				continue;

			}
			break;
			// (Seventh rule)
		case 1:

			// (Eighth rule)

			returnVal = currentSnapshot.inputN * returnVal;

			// (Ninth rule)
			continue;
			break;
		}
	}
	
	// (Second rule)
	return returnVal;
}   
#endif //__LINEAR_RECURSION_H__