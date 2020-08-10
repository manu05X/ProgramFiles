/*
First Depth First Search
Problem Description

You are given n towns (1 to n). All towns are connected via unique directed path as mentioned in the input.

Given 2 towns find whether you can reach the first town from the second without repeating any edge.

x y : query to find whether x is reachable from y.

Input contains an integer array A of size n and 2 integers x and y ( 1 <= x, y <= n ).

There exist a directed edge from A[i] to i+1 for every 1 <= i < n. Also, it's guaranteed that A[i] <= i.

NOTE: Array A is 0-indexed.



Problem Constraints
1 <= n <= 100000



Input Format
First argument is vector A

Second argument is integer B

Third argument is integer C



Output Format
Return 1 if reachable, 0 otherwise.



Example Input
Input 1:

 A = [1, 1, 2]
 B = 1
 C = 2
Input 2:

 A = [1, 1, 2]
 B = 2
 C = 1


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 Tree is 1--> 2--> 3 and hence 1 is not reachable from 2.
Explanation 2:

 Tree is 1--> 2--> 3 and hence 2 is reachable from 1.
 
*/



bool vis[100005];
vector <int>a[100005]; 
bool dfs(int s, int x) 
{ 
	if(s == x) return true; 
	vis[s] == 1; 
	int i, j, k = a[s].size(); 
	for(i = 0; i < k; i++)
	{ 
		j = a[s][i]; 
		if(!vis[j] && dfs(j,x)) 
			return true; 
	} 
	return false; 
}

int Solution::solve(vector<int> &A, const int B, const int C) {
    int i, j, n = A.size(); 
	for(i = 0; i <= n; i++)
	{ 
		a[i].clear(); 
		vis[i] = 0; 
	} 
	for(i = 1; i < n; i++)
	{ 
		a[ A[i] ].push_back( i+1 ); 
	} 
	if(dfs(C, B))
	{ 
		return 1; 
	} 
	return 0; 
}



/*
def dfs(x,B,G,vis,vis1):
    vis[x]=1
    vis1[x]=1
    if x==B:
        return True
    for idx in G[x]:
        
        if vis[idx]==0:
            f = dfs(idx,B,G,vis,vis1)
            if ( f == True):
                return f
    
    vis1[x]=0
    return False
        
class Solution:
    # @param A : list of integers
    # @param B : integer
    # @param C : integer
    # @return an integer
    
    def solve (self ,  A, B, C):

        vis = [0]*(len(A)+1);
        vis1 = [0]*(len(A)+1);
        G =[]
        for i in xrange(len(A)+1):
            G.append([])
        for i,idx in  enumerate (A):
            
            if not i+1==idx:
                G[idx].append(i+1)
                
        dfs(1,B,G,vis,vis1)
        return vis1[C]


*/

