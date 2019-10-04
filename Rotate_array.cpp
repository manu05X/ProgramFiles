#include <iostream>
#include "solution.h"
using namespace std;

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
