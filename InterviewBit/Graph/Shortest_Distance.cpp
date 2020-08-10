/*
Shortest Distance in a graph with two different weights
Problem Description

Given a weighted undirected graph having A nodes, a source node C and destination node D.

Find the shortest distance from C to D and if it is impossible to reach node D from C then return -1.

You are expected to do it in Time Complexity of O(A + M).

Note:

There are no self-loops in the graph.

No multiple edges between two pair of vertices.

The graph may or may not be connected.

Nodes are Numbered from 0 to A-1.

Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



Problem Constraints
1 <= A <= 105

0 <= B[i][0], B[i][1] < A

1 <= B[i][2] <= 2

0 <= C < A

0 <= D < A



Input Format
The first argument given is an integer A, representing the number of nodes.

The second argument given is the matrix B, where B[i][0] and B[i][1] are connected through an edge of weight B[i][2].

The third argument given is an integer C, representing the source node.

The fourth argument is an integer D, representing the destination node.

Note: B[i][2] will be either 1 or 2.



Output Format
Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.



Example Input
Input 1:

 
A = 6
B = [   [2, 5, 1]
        [1, 3, 1] 
        [0, 5, 2] 
        [0, 2, 2] 
        [1, 4, 1] 
        [0, 1, 1] ] 
C = 3
D = 2
Input 2:

A = 2
B = [   [0, 1, 1]
    ] 
C = 0
D = 1


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

The path to be followed will be:
    3 -> 1 (Edge weight : 1)
    1 -> 0 (Edge weight : 1)
    0 -> 2 (Edge weight : 2)
Total length of path = 1 + 1 + 2 = 4.
Explanation 2:

 Path will be 0-> 1.
 
*/



    const int N=200005;
    vector<int> g[N];
    int vis[N];
    
    void clean(int n)
    {
        for(int i=0;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
        }
    }
    
    void make_graph(int n,vector<vector<int>> &edges)
    {
        for(auto &it:edges)
        {
            int x=it[0];
            int y=it[1];
            int w=it[2];
            if(w==1)
            {
                g[x].push_back(y);
                g[y].push_back(x);
            }
            else
            {
                g[x].push_back(x+n);
                g[x+n].push_back(y);
                g[y].push_back(y+n);
                g[y+n].push_back(x);
            }
        }
    }
    
    int shortestDistance(int n,vector<vector<int>>&edges,int source,int destination)
    {
        clean(n+n);
        make_graph(n,edges);
        vis[source]=1;
        queue<pair<int,int>>q;
        q.push({source,0});
        while(!q.empty())
        {
            int x=q.front().first;
            int w=q.front().second;
            q.pop();
            
            if(x==destination)
                return w;
            for(auto &it:g[x])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,w+1});
                }
            }
        }
        return -1;
    }
int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    return shortestDistance(A,B,C,D);
}


/*
from collections import deque
class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @param C : integer
    # @param D : integer
    # @return an integer
    def solve(self, A, B, C, D):
        dum = 0
        
        for i in B:
            dum = max(dum,i[0],i[1])
            
        for i in B:
            n1,n2,weight = i[0],i[1],i[2]
            if weight==2:
                dum +=1
                i[1]=dum
                i[2]=1
                B.append([dum,n2,1])
                
        
        #print(B)
        
        adj = []
        
        for _ in range(dum+1):
            adj.append([])
            
        for i in B:
            adj[i[0]].append(i[1])
            adj[i[1]].append(i[0])
            
        #print(adj)
        
        map = {}
        q = deque()
        q.append([C,0])
        
        while q:
            node = q.popleft()
            n,d = node[0],node[1]
            
            if n==D:
                return d
            
            if n not in map:
                map[n]=1
                for all in adj[n]:
                    q.append([all,d+1])
                    
                    
        return -1

*/

