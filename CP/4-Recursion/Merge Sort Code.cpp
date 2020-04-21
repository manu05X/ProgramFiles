/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8
*/

//sol->
#include <iostream>
#include "solution.h"
using namespace std;

void merge(int *input, int start, int mid, int end)
{
    int temp[end-start+1];
    int i = start, j = mid+1, k = 0;
    
    while (i <= mid && j <= end) {
        if (input[i] <= input[j]) {
            temp[k] = input[i];
            ++i;
        }
        else {
            temp[k] = input[j];
            ++j;
        }
        ++k;
    }
    
    while (i <= mid) {
        temp[k] = input[i];
        ++i; ++k;
    }
    while (j <= end) {
        temp[k] = input[j];
        ++j; ++k;
    }
    
    for (i = start; i <= end; ++i)
        input[i] = temp[i - start];
}

void MergeSort(int *input, int start, int end)
{
    if (start < end) {
        int mid = (start + end)/2;
        MergeSort(input, start, mid);
        MergeSort(input, mid+1, end);
        merge(input, start, mid, end);
    }
}
void mergeSort(int input[], int size){
    MergeSort(input,0,size-1);
        
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
