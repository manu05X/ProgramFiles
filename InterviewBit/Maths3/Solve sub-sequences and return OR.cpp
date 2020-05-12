/*
Solve sub-sequences and return OR
Problem Description
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {2, 3, 5} is a subsequence of {1, 2, 3, 4, 5} obtained after removal of elements {1, 4}. Given is an array of integers A of size N. An array of size N can have (2^N - 1) number of non empty subsequences. For the given function:
 solve (int subsequence[]) {
    int count[];    //array initialised to 0.
    for(int i = 0; i &amp;lt; subsequence.length; i++) {
        number = subsequence[i];
        for(int j = 2; j &amp;lt;= number; j++) {
            if(number % j == 0) {
                count[j]++;
                if(count[j] == subsequence.length)  return 0;
            }
        }
    }
    return 1;
}
If all the subsequences of the array A are passed in the above function. What will be the bitwise OR of all the returned values from the given function.   


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return the bitwise OR of all the returned values.


Example Input
Example Input 1:
 A = [1, 2, 3]
Example Input 2:
 A = [2, 4, 6, 8]
   


Example Output
Example Output 1:
 1
Example Output 2:
 0
   


Example Explanation
Explanation 1:
 If you pass {1} in function, it return 1. as A|1 = 1. answer will be 1.
 
*/

//sol->

int Solution::solve(vector<int> &A) {
    //int ans=0;
    if(A.size()==1)
        return 1;
    for(int i=0;i<A.size()-1;i++)
    {
        int ans=__gcd(A[i],A[i+1]);
        if(ans==1)
            return 1;
    }
    
    return 0;
    
}





/*
int Solution::solve(vector<int> &A) {
    int ans=A[0];
    for(int x:A)
        ans=__gcd(x,ans);
    return ans==1;
}

------------------------

public class Solution {
    public int solve(int[] a) {
        int d = a[0];
        for(int x : a)  d = gcd(d, x);
        return d == 1 ? 1 : 0;
    }
    
    int gcd(int a, int b) {
        if(b == 0)  return a;
        return gcd(b, a % b);
    }
}

*/
