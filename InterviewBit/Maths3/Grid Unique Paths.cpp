/*
Grid Unique Paths
Problem Description
A robot is located at the top-left corner of an A x B grid (marked 'Start' in the diagram below).  The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below). How many possible unique paths are there? 
http://i.imgur.com/3eaivQ5.png

Problem Constraints
A and B will be such that the resulting answer fits in a 32 bit signed integer.


Input Format
First argument of input will be single integer A.
Second argument of input will be single integer B.


Output Format
Return a single integer denoting the number of unique paths.


Example Input
 A = 2, B = 2


Example Output
 2


Example Explanation
 2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
 
*/

//sol->

int Solution::uniquePaths(int A, int B) {
    int arr[A][B];
    
    for(int i=0;i<B;i++)
        arr[0][i]=1;
    
    for(int i=0;i<A;i++)
        arr[i][0]=1;
        
    for(int i=1;i<A;i++)
    {
        for(int j=1;j<B;j++)
        arr[i][j]=arr[i-1][j]+arr[i][j-1];
    }
    return arr[A-1][B-1];
}






/*
int Solution::uniquePaths(int m, int n) {
    // m+n-2 C n-1 = (m+n-2)! / (n-1)! (m-1)! 
    long long ans = 1;
    for (int i = max(n,m); i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - max(n,m) + 1);
    }
    return (int)ans;
}

------------------------

public class Solution {
	public int uniquePaths(int A, int B) {
	    
	    int res = result(A, B);

        return res;	    
	}
	
	public int result(int m, int n) {
	    
	    int res = 1;
	    int num = m + n - 2;
	    m--;
	    n--;
	    
	    if (m == 0 || n == 0)
	        return 1;
	    
	    int max = Math.max(m, n);
	    int val = 1;
	    int count = 0;
	    int min = Math.min(m, n);
	    
	    for (int i = max + 1; i <= num; i++) {
	        res *= i;
	        res /= val;
	        val++;
	    }
	    
	    return res;
	    
	}
}
--------------------
class Solution:
    # @param A : integer
    # @param B : integer
    # @return an integer
    def uniquePaths(self, A, B):
        if A==1 or B==1:
            return 1
        if A==2 or B==2:
            return max(A,B)
        ans = 1
        for i in range(max(A,B), A+B-1):
            ans *= i
            ans //= (i-max(A,B)+1)
        return ans
*/
