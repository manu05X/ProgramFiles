/*
Shortest Distance in a Maze
Problem Description

Given a matrix of integers A of size N x M describing a maze. The maze consists of empty locations and walls.

1 represents a wall in a matrix and 0 represents an empty location in a wall.

There is a ball trapped in a maze. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given two array of integers of size B and C of size 2 denoting the starting and destination position of the ball.

Find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the starting position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.



Problem Constraints
2 <= N, M <= 100

0 <= A[i] <= 1

0 <= B[i][0], C[i][0] < N

0 <= B[i][1], C[i][1] < M



Input Format
The first argument given is the integer matrix A.

The second argument given is an array of integer B.

The third argument if an array of integer C.



Output Format
Return a single integer, the minimum distance required to reach destination



Example Input
Input 1:

A = [ [0, 0], [0, 0] ]
B = [0, 0]
C = [0, 1]
Input 2:

A = [ [0, 0], [0, 1] ]
B = [0, 0]
C = [0, 1]


Example Output
Output 1:

 1
Output 2:

 1


Example Explanation
Explanation 1:

 Go directly from start to destination in distance 1.
Explanation 2:

 Go directly from start to destination in distance 1.
 
*/


const int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};

bool inside(int x,int y,int n,int m)
{
    return (x>=0 && x<=n-1 && y>=0 && y<=m-1);
}
struct Grid
{
    int x,y;
    int d;
    
    Grid(int _x=0,int _y=0,int _d=0):x(_x),y(_y),d(_d){};
    
    bool operator<(const Grid &g) const
    {
        return d>g.d;
    }
};
int findMinimumDistance(vector<vector<int>>& maze,vector<int>& start,vector<int>& destination)
{
    auto &a=maze;
    int n=a.size();
    int m=a[0].size();
    
    int sx=start[0];
    int sy=start[1];
    int ex=destination[0];
    int ey=destination[1];
    
    vector<vector<int>> v(n,vector<int>(m,INT_MAX));
    priority_queue<Grid> pq;
    int i;
    int d,d1;
    int x,y;
    int x1,y1;
    int x2,y2;
    
    pq.push(Grid(sx,sy,0));
    while(!pq.empty() && v[ex][ey]==INT_MAX)
    {
        x=pq.top().x;
        y=pq.top().y;
        d=pq.top().d;
        pq.pop();
        if(v[x][y]!=INT_MAX)
        {
            continue;
        }
        else
        {
            v[x][y]=d;
        }
        
        for(i=0;i<4;i++)
        {
            x1=x;
            y1=y;
            d1=0;
            
            while(true)
            {
                x2=x1+dir[i][0];
                y2=y1+dir[i][1];
                
                if(inside(x2,y2,n,m) && a[x2][y2]==0)
                {
                    x1=x2;
                    y1=y2;
                    ++d1;
                }
                else
                {
                    break;
                }
            }
            if(d1>0 && v[x1][y1]==INT_MAX)
            {
                pq.push(Grid(x1,y1,d+d1));
            }
        }
        
    }
    
    while(!pq.empty())
    {
        pq.pop();
        
    }
    int res=(v[ex][ey]!=INT_MAX ? v[ex][ey]: -1);
    v.clear();
    
    return res;
}
int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    return findMinimumDistance(A,B,C);