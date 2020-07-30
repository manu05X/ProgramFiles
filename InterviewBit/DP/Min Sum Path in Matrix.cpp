/*
Min Sum Path in Matrix
Problem Description

Given a M x N grid A of integers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Return the minimum sum of the path.

NOTE: You can only move either down or right at any point in time.



Problem Constraints
1 <= M, N <= 2000

-1000 <= A[i][j] <= 1000



Input Format
First and only argument is a 2-D grid A.



Output Format
Return an integer denoting the minimum sum of the path.



Example Input
Input 1:

 A = [
       [1, 3, 2]
       [4, 3, 1]
       [5, 6, 1]
     ]
Input 2:

 A = [
       [1, -3, 2]
       [2, 5, 10]
       [5, -5, 1]
     ]


Example Output
Output 1:

 8
Output 2:

 -1


Example Explanation
Explanation 1:

 The path will be: 1 -> 3 -> 2 -> 1 -> 1.
Input 2:

 The path will be: 1 -> -3 -> 5 -> -5 -> 1.
 
*/

int Solution::minPathSum(vector<vector<int> > &A) {
    if(A.size()==0)
        return 0;
        
    int rows=A.size();
    int column=A[0].size();
    
    vector<vector<int>>temp(rows,vector<int>(column));
    int sum=0;
    
    for(int j=0;j<column;j++)
    {
        temp[0][j]=sum+A[0][j];
        sum=temp[0][j];
    }
    
    sum=0;
    
      for(int i=0;i<rows;i++)
    {
        temp[i][0]=sum+A[i][0];
        sum=temp[i][0];
    }
    
        for(int i=1;i<rows;i++)
    {
         for(int j=1;j<column;j++)
            {
                temp[i][j]=A[i][j]+ min(temp[i-1][j],temp[i][j-1]);
            } 
    }
    return temp[rows-1][column-1];
    
}


/*
int Solution::minPathSum(vector<vector<int> > &A) {
    if (A.size() == 0) return 0;
    int m = A.size(), n = A[0].size();
    int minPath[m + 1][n + 1];
    for (int i = 0; i < m; i++) {
        minPath[i][0] = A[i][0]; 
        if (i > 0) minPath[i][0] += minPath[i - 1][0];
        for (int j = 1; j < n; j++) {
            minPath[i][j] = A[i][j] + minPath[i][j-1];
            if (i > 0) minPath[i][j] = min(minPath[i][j], A[i][j] + minPath[i-1][j]);
        }
    }
    return minPath[m-1][n-1];
}
__________________________________________________________
JAVA

public class Solution {
    
    private int mem[][];
    private ArrayList<ArrayList<Integer>> A;
    
	public int minPathSum(ArrayList<ArrayList<Integer>> A) {
	    int m, n;
	    
	    if (A == null || A.size() == 0 || A.get(0).size() == 0)
	        return 0;
	    
	    m = A.size();
	    n = A.get(0).size();
	    
	    mem = new int[m][n];
	    
	    for (int i = 0; i < m; i++)
	        Arrays.fill(mem[i], Integer.MAX_VALUE);
	        
	    mem[0][0] = A.get(0).get(0);
	    
	    this.A = A;
	    rec(m - 1, n - 1);
	    
	    return mem[m - 1][n - 1];
	    
	}
	
	public int rec(int i, int j) {
	    
	    if (i < 0 || j < 0)
	        return Integer.MAX_VALUE;
	    
	    if (mem[i][j] != Integer.MAX_VALUE)
	        return mem[i][j];
	    
	    int res = rec(i - 1, j);
	    res = Math.min(rec(i, j - 1), res);
	    
	    mem[i][j] = res + A.get(i).get(j);
	    
	    return mem[i][j];
	    
	}
	
}
*/
