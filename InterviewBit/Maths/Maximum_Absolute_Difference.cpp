/*
Maximum Absolute Difference

You are given an array of N integers, A1, A2, .... AN.

Return the maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.


Problem Constraints
1 <= N <= 100000 -109 <= A[i] <= 109   


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting the maximum value of f(i, j).


Example Input
Input 1:
A=[1, 3, -1]
  


Example Output
Output 1:
5
  


Example Explanation
Explanation 1:
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/

//sol->

int Solution::maxArr(vector<int> &A) {
    int n = A.size();
    int ans = INT_MIN,max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0;i < n; i++)
    {
        max1 = max(max1,A[i]+i);
        max2 = max(max2,A[i]-i);
        min1 = min(min1,A[i]+i);
        min2 = min(min2,A[i]-i);
    }
    ans = max(max1 - min1,max2-min2);
    return ans;  
}
