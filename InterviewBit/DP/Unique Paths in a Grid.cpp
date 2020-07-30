/*
Unique Paths in a Grid
Problem Description

Given a grid of size n * m, lets assume you are starting at (1,1) and your goal is to reach (n, m). At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be? An obstacle and empty space is marked as 1 and 0 respectively in the grid.



Problem Constraints
1 <= n, m <= 100
A[i][j] = 0 or 1



Input Format
Firts and only argument A is a 2D array of size n * m.



Output Format
Return an integer denoting the number of unique paths from (1, 1) to (n, m).



Example Input
Input 1:

 A = [
        [0, 0, 0]
        [0, 1, 0]
        [0, 0, 0]
     ]
Input 2:

 A = [
        [0, 0, 0]
        [1, 1, 1]
        [0, 0, 0]
     ]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 Possible paths to reach (n, m): {(1, 1), (1, 2), (1, 3), (2, 3), (3, 3)} and {(1 ,1), (2, 1), (3, 1), (3, 2), (3, 3)}  
 So, the total number of unique paths is 2. 
Explanation 2:

 It is not possible to reach (n, m) from (1, 1). So, ans is 0.
 
*/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    int dp[n+1][m+1];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=0;
            if(A[i][j]==1)
            continue;
            if(i==0 && j==0)
                dp[i][j]=1;
            if(i>0)
            dp[i][j]+=dp[i-1][j];
            
            if(j>0)
            dp[i][j]+=dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}





/*
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {

    int m = A.size(), n = A[0].size();
    int uniquePaths[m + 1][n + 1];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            uniquePaths[i][j] = 0;
            if (A[i][j]) continue;
            if (i == 0 && j == 0) uniquePaths[i][j] = 1;
            if (i > 0) uniquePaths[i][j] += uniquePaths[i-1][j];
            if (j > 0) uniquePaths[i][j] += uniquePaths[i][j-1];
        }
    }
    return uniquePaths[m-1][n-1];    
}

___________________________________________________

public class Solution {
    
    private int mem[][];
    private ArrayList<ArrayList<Integer>> A;
    
	public int uniquePathsWithObstacles(ArrayList<ArrayList<Integer>> A) {
	    int m, n;
	    
	    if (A == null)
	        return 0;
	        
	    m = A.size();
	    
	    if (m == 0)
	        return 0;
	        
	    n = A.get(0).size();
	    
	    if (n == 0)
	        return 0;
	    
	    mem = new int[m][n];
	    
	    for (int i = 0; i < m; i++)
	        Arrays.fill(mem[i], -1);
	   
	    this.A = A;
	    if (A.get(0).get(0) == 0)
    	    mem[0][0] = 1;
	
	    rec(m - 1, n - 1);
	    
	    return mem[m - 1][n - 1];
	}
	
	
	public int rec(int i, int j) {
	    
	    if (i < 0 || j < 0)
	        return 0;
	    
	    if (mem[i][j] != -1)
	        return mem[i][j];
	    
	    if (A.get(i).get(j) == 1)
	        return mem[i][j] = 0;
	    
	    mem[i][j] = rec(i - 1, j) + rec(i, j - 1);
	    
	    return mem[i][j];
	}
	
}


*/
