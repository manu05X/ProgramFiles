/*
Minimum Swaps to Sort 
Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 106

User Task:
You don't need to read input or print anything. Your task is to complete the function minSwaps() which takes the array arr[] and its size N as inputs and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 

Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).

Example(To be used only for expected output):
Input:
2
5
1 5 4 3 2
4
8 9 16 15

Output:
2
1

Explanation:
Test Case 1: We need two swaps, swap 2 with 5 and 3 with 4 to make it sorted. 
 
*/

/ { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int n)
{
    // Create an array of pairs where first 
    // element is array element and second element 
    // is position of first element 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    sort(arrPos, arrPos + n); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    // Return result 
    return ans; 
}


/*
Algorithm Concept:
-------------------
1>Look at each index and compare the index position with its element value if its same then move to the next index position.
2>If index position is not the same as element value then treat element value as index value for finding the next element.
3>If we come back to the visited element then there exist a cycle, then count the size of that cycle,
 the number of swaps for particular cycle would be size-1, do this for all the cycles and add them together. 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

import java.util.HashMap;

public class MinSwapArray {

	public static void main(String[] args) {

		int arr[] = new int[] { 1, 4, 3, 2 };

		boolean isVisited[] = new boolean[arr.length + 1];

		HashMap<Integer, Integer> nodeMap = new HashMap<Integer, Integer>();

		for (int i = 1; i < isVisited.length; i++) {
			nodeMap.put(i, arr[i - 1]);
		}
		int countSwap = 0;

		for (int k = 1; k <= nodeMap.size(); k++) {

			int nextNode;

			if (isVisited[k] == false) {
				isVisited[k] = true;

				if (k == nodeMap.get(k)) {
					continue;
				} else {
					int c = nodeMap.get(k);
					while (!isVisited[c]) {

						isVisited[c] = true;

						nextNode = nodeMap.get(c);
						c = nextNode;
						++countSwap;
					}
				}
			}
		}

		System.out.println("swap count :" + countSwap);
	}
}
*/

