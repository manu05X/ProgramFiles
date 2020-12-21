/*
Largest subarray with 0 sum
*/

#include <bits/stdc++.h> 
using namespace std; 

// Driver Code 
int main() 
{ 
    int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of the longest 0 sum subarray is "
         << maxLen(arr, n); 
  
    return 0; 
}

int maxLen(int A[], int n)
{
    // Map to store the previous sum
    unordered_map<int, int> mp;
    int preSum = 0, maxLen = 0;
    
    for(int i = 0; i < n; i++)
    {
        // Add current element to PreSum 
        preSum += A[i];
        // if preSum is 0 then maxLen  = CurrIndex + 1
        if(preSum == 0)
        {
            maxLen = i + 1;
        }
        else
        {
            /*finding preSum in map */
            if(mp.find(preSum) != mp.end())
            {
                //if preSum is in map then compute its lenth i.e (currIndex - mapIndex of preSum)
                maxLen = max(maxLen, i - mp[preSum]);
            }
            else
            {
                //insert the preSum in map at curr Index
                mp[preSum] = i;
            }
        }
    }
    return maxLen;
}
