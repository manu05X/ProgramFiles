/*
Detect cycle in an undirected graph 
Given a Undirected Graph. Check whether it contains a cycle or not. 

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' testcases follow. Each testcase consists of two lines. Description of testcases are as follows: The First line of each testcase contains two integers 'N' and 'M' which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is a bidirectional  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
You don't need to read input or print anything. Your task is to complete the function isCyclic which takes the Graph and the number of vertices as inputs and returns true if the given undirected graph contains any cycle. Else, it returns false.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= M <= (N*(N-1))/2
0 <= u, v <=  N-1
Graph doesn't contain multiple edges and self loops.

Example:
Input:
3
2 1
0 1
4 3
0 1 1 2 2 3
5 4
0 1 2 3 3 4 4 2

Output:
0
0
1

Explanation:
Testcase 1: There is a graph with 2 vertices and 1 edge from 0 to 1. So there is no cycle.
Testcase 2: There is a graph with 3 vertices and 3 edges from 0 to 1, 1 to 2 and 2 to 3.
Testcase 3: There is a cycle in the given graph formed by vertices 2, 3 and 4.

** For More Input/Output Examples Use 'Expected Output' option **

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

/*
Gives TLE
bool isCyclic_util(vector<int> adj[], vector<int> visited, int curr)
{
    if(visited[curr]==2)
        return true;
    
    visited[curr] = 1;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();++i)
    {
        if(visited[adj[curr][i]]==1)
            visited[adj[curr][i]] = 2;
        else
        {
            FLAG = isCyclic_util(adj, visited, adj[curr][i]);
            if(FLAG==true)
                return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V)
{
   vector<int> visited(V,0);
   bool FLAG = false;
   for(int i=0;i<V;++i)
   {
        visited[i] = 1;
        for(int j=0;j<adj[i].size();++j)
        {
            FLAG = isCyclic_util(adj,visited,adj[i][j]);
            if(FLAG==true)
                return true;
        }
        visited[i] = 0;
   }
   return false;
}
*/


/*
https://stackoverflow.com/questions/61877307/detect-cycle-in-an-undirected-graph
*/

bool bfsUtil(int s,vector<bool> &visited,vector<int> adj[],vector<int> &parent) {
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()) {
        int vertex=q.front();
        q.pop();
        for(int i=0;i<adj[vertex].size();i++) {
            if(adj[vertex][i] == parent[vertex])
                continue;
            if(!visited[adj[vertex][i]]) {
                visited[adj[vertex][i]]=true;
                q.push(adj[vertex][i]);
                parent[adj[vertex][i]] = vertex;
            } else {
                //cycle detected;
                return true;
            }
        }
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
   vector<bool> visited(V,false);
   vector<int> parent(V, -1); // -1 means no parent assigned
   for(int i=0;i<V;i++){
       if(!visited[i]) {
          if(bfsUtil(i,visited,adj,parent)) return true;
       }
   }

   return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}

