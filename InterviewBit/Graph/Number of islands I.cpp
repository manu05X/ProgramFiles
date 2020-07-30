/*
Number of islands
Problem Description

Given a matrix of integers A of size N x M consisting of 0 and 1. A group of connected 1's forms an island. From a cell (i, j) such that A[i][j] = 1 you can visit any cell that shares a corner with (i, j) and value in that cell is 1.

More formally, from any cell (i, j) if A[i][j] = 1 you can visit:

(i-1, j) if (i-1, j) is inside the matrix and A[i-1][j] = 1.
(i, j-1) if (i, j-1) is inside the matrix and A[i][j-1] = 1.
(i+1, j) if (i+1, j) is inside the matrix and A[i+1][j] = 1.
(i, j+1) if (i, j+1) is inside the matrix and A[i][j+1] = 1.
(i-1, j-1) if (i-1, j-1) is inside the matrix and A[i-1][j-1] = 1.
(i+1, j+1) if (i+1, j+1) is inside the matrix and A[i+1][j+1] = 1.
(i-1, j+1) if (i-1, j+1) is inside the matrix and A[i-1][j+1] = 1.
(i+1, j-1) if (i+1, j-1) is inside the matrix and A[i+1][j-1] = 1.
Return the number of islands.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 100

0 <= A[i] <= 1



Input Format
The only argument given is the integer matrix A.



Output Format
Return the number of islands.



Example Input
Input 1:

 A = [ 
       [0, 1, 0]
       [0, 0, 1]
       [1, 0, 0]
     ]
Input 2:

 A = [   
       [1, 1, 0, 0, 0]
       [0, 1, 0, 0, 0]
       [1, 0, 0, 1, 1]
       [0, 0, 0, 0, 0]
       [1, 0, 1, 0, 1]    
     ]


Example Output
Output 1:

 2
Output 2:

 5


Example Explanation
Explanation 1:

 The 1's at position A[0][1] and A[1][2] forms one island.
 Other is formed by A[2][0].
Explanation 2:

 There 5 island in total.
 
*/


int dir[][2]={{0,1},{1,0},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};
int tc=0;

int visited[1005][1005];

bool check(int i,int j,int n,int m,vector<vector<int>> &A)
{
    return (i>=0 && i<n && j>=0 &&j<m &&(A[i][j]==1) && visited[i][j]!=tc);
}

void dfs(int i,int j,int n,int m,vector<vector<int>> &A)
{
    visited[i][j]=tc;
    int di,dj;
    
    for(int k=0;k<8;k++)
    {
        di=i+dir[k][0];
        dj=j+dir[k][1];
        
        if(check(di,dj,n,m,A))
            dfs(di,dj,n,m,A);
    }
}

int solveit(vector<vector<int>> A)
{
    int n=A.size();
    int m=A[0].size();
    assert(n>=1 && n<=100);
    assert(m>=1 && m<=100);
    ++tc;
    int  numberofislands=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1 && visited[i][j]!=tc)
            {
                dfs(i,j,n,m,A);
                ++numberofislands;
            }
        }
    }
    return numberofislands;
}
int Solution::solve(vector<vector<int> > &A) {
    return solveit(A);
}
