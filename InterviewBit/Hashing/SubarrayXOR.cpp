//Count the number of subarrays having a given XOR
//link - https://youtu.be/lO9R5CaGRPY
/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 
 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 2 are {5}
              and {5, 6, 7, 8, 9}
*/

// A simple C++ Program to count all subarrays having
// XOR of elements as given value m
#include <bits/stdc++.h>
using namespace std;

// Simple function that returns count of subarrays
// of arr with XOR value equals to m
int subarrayXor(vector<int> arr, int n, int B)
{
    //map declaration
	map<int, int> freq;
    int count = 0;
    int xorr = 0;

    for(auto it: arr)
    {
        xorr = xorr ^ it;   // computing prefixXOR
        // if it is giving prefi XOR B, so increase the count
        if(xorr == B)
        {
            count++;
        }

        // if predixXOR XOR B exist in map then increase the count by number of time it exist in map
        if(freq.find(xorr ^ B) != freq.end())
        {
            count += freq[xorr^B];
        }
        freq[xorr] += 1; // now insert in map
    }
    return count;

}

// Driver program to test above function
int main()
{
	vector<int> arr { 4, 2, 2, 6, 4 };
    int n = arr.size();
	int m = 6;

	cout << "Number of subarrays having given XOR is "
		<< subarrayXor(arr, n, m);
	return 0;
}


//JAVA
/*
public class Solution{
    public int solve(int [A], int B)
    {
        HashMap<Integer, Integer> freq = new HashMao<Integer, Integer>();
        int cnt = 0;
        int xorr = 0;
        int n = A.length;
        for(int i = 0; i < n; i++)
        {
            xorr = xorr ^ A[i];

            if(freq.get(xorr ^ B) != null)
                cnt += freq.get(xorr ^ B);
            
            if(xorr == B)
            {
                cnt++;
            }
            if(freq.get(xorr) != null)
                freq.put(xorr, freq.get(xorr) + 1);
            else
                freq.get(xorr, 1);            
        }
        return cnt;
    }
}
*/

