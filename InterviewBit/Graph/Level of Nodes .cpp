/*
Level of Nodes 
Given an Undirected Graph and a node X. The task is to find the level of X from 0.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'V' and 'E'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v . The final line contains X whose level you have to find.

Output:
For each testcase, print the level of the given node X.

Your Task:
You don't need to read input or print anything. Your task is to complete the function levels() which takes the graph, number of vertices (V) and a node (X) as inputs and returns the level of X relative to the node 0. If X does not exist in the graph or is not connected (directly/indirectly) to 0 then return -1.
Refer the following image for more details:


Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
1 <= E, V <= 102
1 <= X <= 102

Example:
Input:
2
8 8
0 1 0 2 1 3 1 4 1 5 2 6 6 7 2 5
7
2 1
0 1
1

Output:
3
1

Explanation:
Testcases 1: In the given graph(above), 7 is at 3rd level starting from source node 0 which is at 0th level.
 
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to find level of node X

g[] : adjacency list of the given graph
N : number of vertices
X : The destination node
*/
int levels(vector<int> g[], int N, int X)
{
    /*
	// int x=0;
    // // array to store level of each node 
    // int level[V]; 
    // bool marked[V]; 
  
    // // create a queue 
    // queue<int> que; 
  
    // // enqueue element x 
    // que.push(x); 
  
    // // initialize level of source node to 0 
    // level[x] = 0; 
  
    // // marked it as visited 
    // marked[x] = true; 
  
    // // do until queue is empty 
    // while (!que.empty()) { 
  
    //     // get the first element of queue 
    //     x = que.front(); 
  
    //     // dequeue element 
    //     que.pop(); 
  
    //     // traverse neighbors of node x 
    //     for (int i = 0; i < graph[x].size(); i++) { 
    //         // b is neighbor of node x 
    //         int b = graph[x][i]; 
  
    //         // if b is not marked already 
    //         if (!marked[b]) { 
  
    //             // enqueue b in queue 
    //             que.push(b); 
  
    //             // level of b is level of x + 1 
    //             level[b] = level[x] + 1; 
  
    //             // mark b 
    //             marked[b] = true; 
    //         } 
    //     } 
    // }
    // int count=0; 
    // for (int i = 0; i < V; i++)  
    //     if (level[i] == X) 
    //         count = i; 
    // return count;
	*/
    
    int level=0,ans;
    
    if(X==0)
        return 0;
    
    queue<int> q;
    vector<bool> vis(N,false);
    
    q.push(0);
    vis[0]=true;
    
    while(!q.empty()){
        
        int len = q.size();
        
        while(len--){
            int temp = q.front();
            q.pop();
            
            if(temp==X)
                    return level;
        
            for(int neighbour: g[temp]){
                
                if(!vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = true;
                }
            }
        }
        level++;
    }
    
    return -1;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,E;
		cin>>N>>E;
		
		vector<int> adj[N];
		
		for(int i = 0; i < E; i++)
		{
			int v,u;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int x;
		cin>>x;
		
		cout << levels(adj, N,x)<<endl;
	}
	return 0;
}


