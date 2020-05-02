/*
Rearrange the array
Given an array of integers A of size N that is a permutation of [0, 1, 2, ..., (N-1)]. Rearrange the array such that A[i] = j is changed to A[j] = i for all i and j form 0 to N-1. Note: Try solving this with O(1) extra space. 
Input Format
The only argument given is the integer array A.
Output Format
Return the rearranged array A.
Constraints
1 <= N <= 100000
0 <= A[i] < N
For Example
Input 1:
    A = [1, 2, 3, 4, 0]
Output 1:
    [4, 0, 1, 2, 3]

Input 2:
    A = [2, 0, 1, 3]
Output 2:
    [1, 2, 0, 3]
*/

//sol->

void rearrangeUtil(vector<int> &arr, int n, int i) 
{ 
    // 'val' is the value to be stored at 'arr[i]' 
    int val = -(i+1);  // The next value is determined 
                       // using current index 
    i = arr[i] - 1;  // The next index is determined 
                     // using current value 
  
    // While all elements in cycle are not processed 
    while (arr[i] > 0) 
    { 
        // Store value at index as it is going to be 
        // used as next index 
        int new_i = arr[i] - 1; 
  
        // Update arr[] 
        arr[i] = val; 
  
        // Update value and index for next iteration 
        val = -(i + 1); 
        i = new_i; 
    } 
} 

vector<int> Solution::solve(vector<int> &A) {
      int n = A.size();
    
    int i; 
    for (i=0; i<n; i++) 
        A[i]++; 
  
    // Process all cycles 
    for (i=0; i<n; i++) 
    { 
       // Process cycle starting at arr[i] if this cycle is 
       // not already processed 
       if (A[i] > 0) 
          rearrangeUtil(A, n, i); 
    } 
  
    // Change sign and values of arr[] to get the original 
    //  values back, i.e., values in range from 0 to n-1 
    for (i=0; i<n; i++) 
          A[i] = (-A[i]) - 1; 
    
    return A;
}


/*
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n); 
  
    // Store result in temp[] 
    for (int i=0; i<n; i++) 
      ans[A[i]] = i; 
  
    return ans;
}
*/