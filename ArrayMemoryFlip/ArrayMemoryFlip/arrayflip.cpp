/*

http://www.reddit.com/r/dailyprogrammer/comments/2mkh5g/weekly_17_mini_challenges/cm9d697
---
Array Memory Flip:
Given: An Array of Integers.
Challenge: We want to reverse the order of the array in memory and you are only allowed the array and 1 integer
	variable to do this. No pre-canned library calls or frameworks are not allowed. You must do all the work.
Bonus: Can it be done with just the array and no other allocated storage or variables (outside index counters/pointers
	are okay but storage wise only the array. Cannot just allocate a 2nd array in memory and copy over values)
---
Sample Output: 9876543210

*/

#include <iostream>

using namespace std;

int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int a;
	// Note: While this isn't explicitly allowed in the challenge, all this does is reduce the queries the system  
	//		has to make.
	int arrLen = sizeof(arr)/sizeof(*arr);

	for( int i=0; i<arrLen/2; i++ )
	{
		a = arr[arrLen-1-i];
		arr[arrLen-1-i] = arr[i];
		arr[i] = a;
	}

	for( int i=0; i<arrLen; i++ ) { cout << arr[i]; }

	return 0;
}