/*
Single Element in a Sorted Array


Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10^9



Input Format
The only argument given is the integer array A.



Output Format
Return the single element that appears only once.



Example Input
Input 1:

A = [1, 1, 7]
Input 2:

A = [2, 3, 3]


Example Output
Output 1:

 7
Output 2:

 2


Example Explanation
Explanation 1:

 7 appears once
Explanation 2:

 2 appears once
 
 
*/

int Solution::solve(vector<int> &A) {
     int n = A.size();
        if (n == 1) 
            return A[1];
        
        for (int i=0,j=1;i<n-1;i+=2){
            if (A[i]!=A[j]){
                return A[i];
            }
            j+=2;
        }
        return A[n-1];
}
