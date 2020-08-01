/*
Rotten Oranges
Problem Description

Given a matrix of integers A of size N x M consisting of 0, 1 or 2.

Each cell can have three values:

The value 0 representing an empty cell.

The value 1 representing a fresh orange.

The value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.

Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



Problem Constraints
1 <= N, M <= 1000

0 <= A[i][j] <= 2



Input Format
The first argument given is the integer matrix A.



Output Format
Return the minimum number of minutes that must elapse until no cell has a fresh orange.

If this is impossible, return -1 instead.



Example Input
Input 1:

A = [   [2, 1, 1]
        [1, 1, 0]
        [0, 1, 1]   ]
Input 2:

 
A = [   [2, 1, 1]
        [0, 1, 1]
        [1, 0, 1]   ]


Example Output
Output 1:

 4
Output 2:

 -1


Example Explanation
Explanation 1:

 Max of 4 using (0,0) , (0,1) , (1,1) , (1,2) , (2,2)
Explanation 2:

 Task is impossible
*/
int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
const int inf=99999999;

int solveit(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int distance[n][m];
        queue<pair<int,int> > q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1||grid[i][j]==0)
                    distance[i][j]=inf;
                 else {
                     distance[i][j]=0;
                     q.push({i,j});
                 }
            }
        }
        int x,y;

        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            int dx,dy;
            for(int k=0; k<4; ++k){
                dx=x+dir[k][0];
                dy=y+dir[k][1];
                if(dx >= 0 && dx < n && dy >= 0 && dy < m& & grid[dx][dy] == 1 && distance[x][y]+1 < distance[dx][dy])
				{
                    distance[dx][dy] = 1+distance[x][y];
                    q.push({dx,dy});
                }
            }

        }
        int ans=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    ans=max(ans,distance[i][j]);
                }
            }
        }
        return (ans==inf?-1:ans);
}

int Solution::solve(vector<vector<int> > &A) {
    return solveit(A);
}

/*
int Solution::solve(vector<vector<int> > &A) 
{
    queue<pair<int,int> > q;
    int ans=0;
    for(int i=0;i<A.size();i++)
	{
        for(int j=0;j<A[0].size();j++)
		{
            if(A[i][j]==2)
			{
                pair<int,int> p = make_pair(i,j);
                q.push(p);
            }
        }
    }
    
    if(q.empty())
	{
        return -1;
    }
    else
	{
        pair<int,int> p = make_pair(-1,-1);
        q.push(p);    
    }
    
    while(!q.empty())
	{
        pair <int,int> p= q.front();
        q.pop();
		
        int i=p.first;
        int j=p.second;
        if(i==-1&&j==-1)
		{
            if(!q.empty())
			{
                ans++;
                pair<int,int> p= make_pair(-1,-1);
                q.push(p); 
            }
        }
        else{
            bool check=false;
            if(i-1>=0&&i-1<A.size())
			{
                if(A[i-1][j]==1)
				{
                    A[i-1][j]=2;
                    pair<int,int> p = make_pair(i-1,j);
                    q.push(p);
                }
            }
            
            if(i+1>=0&&i+1<A.size())
			{
                if(A[i+1][j]==1)
				{
                    A[i+1][j]=2;
                    pair<int,int> p = make_pair(i+1,j);
                    q.push(p);
                }
            }
            
            if(j-1>=0&&j-1<A[0].size())
			{
                if(A[i][j-1]==1)
				{
                    A[i][j-1]=2;
                    pair<int,int> p = make_pair(i,j-1);
                    q.push(p);
                }
            }
            
            if(j+1>=0&&j+1<A[0].size())
			{
                if(A[i][j+1]==1)
				{
                    A[i][j+1]=2;
                    pair<int,int> p = make_pair(i,j+1);
                    q.push(p);
                }
            }
            
        }
        
    }
    
    for(int i=0;i<A.size();i++)
	{
        for(int j=0;j<A[0].size();j++)
		{
            if(A[i][j]==1){
                return -1;
            }
        }
    }
    return ans;
}
______________________________________________________________________________
class Solution {
public:
int k=0;

struct test{
    int x,y,z;
    
};
int orangesRotting(vector<vector<int>>& grid) 
{
    
    queue<test>q;
    int n=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(grid[i][j]==2 )
                q.push({i,j,0});
            if(grid[i][j]==1)
                n++;
        }
    }
    int res=0;
    while(q.empty()==false)
    {
        test t=q.front();
        q.pop();
        int a=t.x;
        int b=t.y;
        int c=t.z;
        if(a!=0)
        {
            if(grid[a-1][b]==1)
            {
                grid[a-1][b]=2;
                q.push({a-1,b,c+1});
                n--;
            }
            
            
        }
        if(a!=grid.size()-1)
        {
            if(grid[a+1][b]==1)
            {
                grid[a+1][b]=2;
                q.push({a+1,b,c+1});
                n--;
            }
            
            
        }
        if(b!=0)
        {
            if(grid[a][b-1]==1)
            {
                grid[a][b-1]=2;
                q.push({a,b-1,c+1});
                n--;
            }
            
            
        }
        if(b!=grid[a].size()-1)
        {
            if(grid[a][b+1]==1)
            {
                grid[a][b+1]=2;
                q.push({a,b+1,c+1});
                n--;
            }
            
            
        }
        res=c;
    }
    if(n!=0)
        return -1;
    else
        return res;
}
};
*/