/*
Special Integer

Given an array of integers A and an integer B, find and return the maximum value K such that there is no subarray in A of size K with sum of elements greater than B.



Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 10^9

1 <= B <= 10^9



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the maximum value of K (sub array length).



Example Input
Input 1:

A = [1, 2, 3, 4, 5]
B = 10
Input 2:

A = [5, 17, 100, 11]
B = 130


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

Constraints are satisfied for maximal value of 2.
Explanation 2:

Constraints are satisfied for maximal value of 3.
 
*/

int Solution::solve(vector<int> &A, int x) {
   int n=A.size();
   int curr_sum=0,min_len=n+1;
   
   int start=0,end=0;
   while(end<n)
   {
       while(curr_sum<=x && end< n)
       curr_sum+=A[end++];
       
    while(curr_sum>x && start<n)
    {
        if(end-start<min_len)
            min_len=end-start;
            
        curr_sum -=A[start++];
    }
   }
   return min_len-1;
}



/*

public class Solution {
    
    boolean check(int a[], int b, int m) {
        long s = 0;
        for(int i = 0; i < m; i++)  s += a[i];
        if(s > b)   return false;
        for(int i = m; i < a.length; i++) {
            s += a[i] - a[i-m];
            if(s > b)   return false;
        }
        return true;
    }
    
    public int solve(int[] a, int b) {
        int l = 1, r = a.length;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(check(a, b, m))    l = m + 1;
            else        r = m - 1;
        }
        return l-1;
    }
}

*/
