/*
company 24*7 game

Max length increasing super array made by joining two increasing subarray

Problem: Given an array, find two increasing subarrays(say a and b) such that when joined they produce one increasing array(say ab). We need to find max possible length of array ab.

For example: given array = [2 3 1 2 5 4 5]

Two sub arrays are a = [2 3], b = [4, 5] and ab = [2 3 4 5] Output: length(ab) = 4

*/

//sol->

#include <bits/stdc++.h>
using namespace std; 

    int main()
    {
        int T;
        cin>>T;
        while(T--)
        {
            int n;
            cin>>n;
            
            int arr[n];
            
            for(int i = 0; i <n; i++)
            {
                cin>>arr[i];
            }
            
           if(arr == NULL || n == 0) { return 0; }
            
        
            int nums[n]; 
            int max = 0; 
        
            // Initialize LIS values for all indexes 
            for ( int i = 0; i < n; i++ ) {
                nums[i] = 1; 
            }
        
            // Compute optimized LIS values in bottom up manner 
            for (int i = 1; i < n; i++ ) 
            {
                for ( int j = 0; j < i; j++ )  
                {
                    if ( arr[i] > arr[j] && nums[i] < nums[j] + 1) 
                    {
                        nums[i] = nums[j] + 1; 
                    }
                } 
            }
             for (int i = 1; i < n; i++ ) 
             {
                 if(nums[i]>nums[i-1])
                    max = nums[i];
             }
             
             cout<<max;
        }   
    }