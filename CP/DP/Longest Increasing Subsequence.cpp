/*
Input  : arr[] = {3, 10, 2, 1, 20}
Output : Length of LIS = 3
The longest increasing subsequence is 3, 10, 20

Input  : arr[] = {3, 2}
Output : Length of LIS = 1
The longest increasing subsequences are {3} and {2}

Input : arr[] = {50, 3, 10, 7, 40, 80}
Output : Length of LIS = 4
The longest increasing subsequence is {3, 7, 40, 80}
*/

#include <iostream>
using namespace std;

int LIS(int* input, int n) 
{
	int* output = new int[n];
	output[0] = 1;
	
/* Compute optimized LIS values in bottom up manner */	
	for (int i = 1; i < n; i++) 
	{
		output[i] = 1;
		
		for (int j = i - 1; j >= 0; j--) 
		{
			if (input[j] > input[i]) 
			{
				continue;
			}
			
			int possibleAns = output[j] + 1;
			if (possibleAns > output[i]) 
			{
				output[i] = possibleAns;
			}
		}
	}	
	/* Return maximum value in best*/ 
	int best = 0;     
	for (int i = 0; i < n; i++) 
	{
		if (best < output[i]) 
		{
			best = output[i];
		}
	}
	delete [] output;
	return best;
	
	
	
		/*M2->Compute optimized LIS values in bottom up manner
	int lis[n]; 
   
    lis[0] = 1;
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  */
    /* Return maximum value in lis[] 
    return *max_element(lis, lis+n); */
}

int main() 
{
	int n;
	cin >> n;
	int * input = new int[n];
	
	for (int i = 0; i < n; i++) 
	{
		cin >> input[i];
	}
	int ans = LIS(input, n);
	cout << ans << endl;
	delete [] input;
}
