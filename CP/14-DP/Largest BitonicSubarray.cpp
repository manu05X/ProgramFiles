#include<iostream>
using namespace std;
#include "solution.h"

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}

 	
	int longestBitonicSubarray(int *arr, int size) {
          // Length of increasing subarray ending at all indexes
   int *increasingSubSeq = new int[size];          //create increasing sub sequence array
   for (int i = 0; i < size; i++)
      increasingSubSeq[i] = 1;              //set all values to 1

   for (int i = 1; i < size; i++)           //compute values from left ot right
      for (int j = 0; j < i; j++)
         if (arr[i] > arr[j] && increasingSubSeq[i] < increasingSubSeq[j] + 1)
            increasingSubSeq[i] = increasingSubSeq[j] + 1;

   int *decreasingSubSeq = new int [size];       //create decreasing sub sequence array
   for (int i = 0; i < size; i++)
      decreasingSubSeq[i] = 1;              //set all values to 1

   for (int i = size-2; i >= 0; i--)          //compute values from left ot right
      for (int j = size-1; j > i; j--)
         if (arr[i] > arr[j] && decreasingSubSeq[i] < decreasingSubSeq[j] + 1)
            decreasingSubSeq[i] = decreasingSubSeq[j] + 1;

   int max = increasingSubSeq[0] + decreasingSubSeq[0] - 1;
   for (int i = 1; i < size; i++) //find max length
      if (increasingSubSeq[i] + decreasingSubSeq[i] - 1 > max)
         max = increasingSubSeq[i] + decreasingSubSeq[i] - 1;
   return max;
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	
 	}
	
	//*****OTHER SOLUTION*****
	
	 	
	int longestBitonicSubarray(int *arr, int size) {
          // Length of increasing subarray ending at all indexes
   int *increasingSubSeq = new int[size];          //create increasing sub sequence array
   for (int i = 0; i < size; i++)
      increasingSubSeq[i] = 1;              //set all values to 1

   for (int i = 1; i < size; i++)           //compute values from left ot right
      for (int j = 0; j < i; j++)
         if (arr[i] > arr[j] && increasingSubSeq[i] < increasingSubSeq[j] + 1)
            increasingSubSeq[i] = increasingSubSeq[j] + 1;

   int *decreasingSubSeq = new int [size];       //create decreasing sub sequence array
   for (int i = 0; i < size; i++)
      decreasingSubSeq[i] = 1;              //set all values to 1

   for (int i = size-2; i >= 0; i--)          //compute values from left ot right
      for (int j = size-1; j > i; j--)
         if (arr[i] > arr[j] && decreasingSubSeq[i] < decreasingSubSeq[j] + 1)
            decreasingSubSeq[i] = decreasingSubSeq[j] + 1;

   int max = increasingSubSeq[0] + decreasingSubSeq[0] - 1;
   for (int i = 1; i < size; i++) //find max length
      if (increasingSubSeq[i] + decreasingSubSeq[i] - 1 > max)
         max = increasingSubSeq[i] + decreasingSubSeq[i] - 1;
   return max;
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
     	
     	
     	
 	}



