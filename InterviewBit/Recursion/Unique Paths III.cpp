/*
Unique Paths III
Problem Description

Given a matrix of integers A of size N x M . There are 4 types of squares in it:

1. 1 represents the starting square.  There is exactly one starting square.
2. 2 represents the ending square.  There is exactly one ending square.
3. 0 represents empty squares we can walk over.
4. -1 represents obstacles that we cannot walk over.
Find and return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
2 <= N * M <= 20
-1 <= A[i] <= 2



Input Format
The first argument given is the integer matrix A.



Output Format
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.



Example Input
Input 1:

A = [   [1, 0, 0, 0]
        [0, 0, 0, 0]
        [0, 0, 2, -1]   ]
Input 2:

A = [   [0, 1]
        [2, 0]    ]


Example Output
Output 1:

2
Output 2:

0


Example Explanation
Explanation 1:

We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Explanation 1:

Answer is evident here. 

*/

//sol->


void explore(int i,int j,int n,int m,unordered_set<int>visited,int &count,int k,vector<vector<int>>& grid)
{
    if(i<0 ||i>=n||j<0||j>=m||visited.count(i*m+j)>0 || grid[i][j]==-1)
        return;
    if(grid[i][j]==2)
    {
        if(visited.size()==k)
            count++;
    }
    visited.insert(i*m+j);
    explore(i+1,j,n,m,visited,count,k,grid);
    explore(i,j+1,n,m,visited,count,k,grid);
    explore(i-1,j,n,m,visited,count,k,grid);
    explore(i,j-1,n,m,visited,count,k,grid);
}
int Solution::solve(vector<vector<int> > &A) {
    int k=1;
    int n=A.size();
    int m=A[0].size();
    for(auto i:A)
    {
        for(auto j:i)
            if(j==0)
                k++;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1)
            {
                unordered_set<int>visited;
                explore(i,j,n,m,visited,count,k,A);
            }
        }
    }
    return count;
}






/*
int n, m, ans;
int xx[4] = {1, 0, 0, -1};
int yy[4] = {0, 1, -1, 0};

bool isV(int u, int v, vector<vector<int> > A) {
    return 0 <= u && u < n && 0 <= v && v < m && A[u][v] != -1;
}

void recur(int x, int y, int cnt, vector<vector<int> > A) {
    if(A[x][y] == 2) {
        if(cnt == 0)    ans++;
        return;
    }
    A[x][y] = -1;
    for(int i = 0; i < 4; i++) {
        int u = x + xx[i];
        int v = y + yy[i];
        if(isV(u, v, A)) {
            recur(u, v, cnt - 1, A);
        }
    }
    A[x][y] = 0;
}
    
int Solution::solve(vector<vector<int> > &A) {

    n = A.size();   m = A[0].size();
    ans = 0;
    int u = -1, v = -1, cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 1) {
                u = i;    v = j;
            } else if(A[i][j] == 0)    cnt++;
        }
    }
    assert(u != -1);
    recur(u, v, cnt + 1, A);
    return ans;    
}


----------------------------------

xx = [1, 0, 0, -1]
yy = [0, 1, -1, 0]
def isV(u, v, A):
    return 0 <= u and u < len(A) and 0 <= v and v < len(A[0]) and A[u][v] != -1

def recur(x, y, cnt, A):
    if  A[x][y] == 2: 
        if cnt == 0:
            return 1
        return 0
    A[x][y] = -1
    
    ans = 0
    for i in range(4): 
        u = x + xx[i]
        v = y + yy[i]
        if isV(u, v, A): 
           ans += recur(u, v, cnt - 1, A)

    A[x][y] = 0
    return ans
class Solution:
# @param A : list of list of integers
# @return an integer
    def solve(self, A):
        ans = 0
        u, v, cnt = -1, -1, 0
        for i in range(len(A)):
            for j in range(len(A[0])): 
                if  A[i][j] == 1: 
                    u = i    
                    v = j
                elif A[i][j] == 0:
                    cnt+=1

        assert(u != -1)
        return recur(u, v, cnt + 1, A)

*/
