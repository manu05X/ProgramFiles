/*
Rotate array
Send Feedback
Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d
Output Format :
Updated array elements (separated by space)
Constraints :
1 <= N <= 1000
1 <= d <= N
Sample Input :
7
1 2 3 4 5 6 7
2
Sample Output :
3 4 5 6 7 1 2
*/

#include <iostream>
#include "solution.h"
using namespace std;
// arr - input array
// size - size of array
// d - array to be rotated by d elements
void rightRotateByOne(int arr[], int size)
{
	int first = arr[0];
	for (int i = 0; i < size-1; i++)
		arr[i] = arr[i+1];

	arr[size-1] = first;
}


void Rotate(int arr[], int d, int size) {
    for (int i = 0; i < d; i++)
		rightRotateByOne(arr, size);
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */}	

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}

