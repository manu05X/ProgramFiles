#include <iostream>
using namespace std;
#include "solution.h"

int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << MissingNumber(input, size);	
	
	delete [] input;

	return 0;
}
// arr - input array
// size - size of array

int MissingNumber(int arr[], int size){
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    
    int n=size;
    int sumT=((n-1)*(n-2))/2;
    
    return sum-sumT;/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    

}
