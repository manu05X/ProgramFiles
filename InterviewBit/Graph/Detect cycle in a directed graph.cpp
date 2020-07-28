/*

Detect cycle in a directed graph 
Given a Directed Graph. Check whether it contains any cycle or not.

Input: The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is an uni-directed  edge from u to v .

Output:
The method should return 1 if there is a cycle else it should return 0.

User task:
You don't need to read input or print anything. Your task is to complete the function isCyclic which takes the Graph and the number of vertices and inputs and returns true if the given directed graph contains a cycle. Else, it returns false.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 1000
1<= N,M <= 1000
0 <= u,v <= N-1

Example:
Input:
3
2 2
0 1 0 0
4 3
0 1 1 2 2 3
4 3
0 1 2 3 3 2
Output:
1
0
1

Explanation:
Testcase 1: In the above graph there are 2 vertices. The edges are as such among the vertices.
https://media.geeksforgeeks.org/wp-content/uploads/20190416150635/DirectedGraph2.jpg

From graph it is clear that it contains cycle.

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
bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr)
{
    if(visited[curr]==true)
        return true;
    
    visited[curr] = true;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();++i)
    {
        FLAG = isCyclic_util(adj, visited, adj[curr][i]);
        if(FLAG==true)
            return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
   vector<bool> visited(V,false);
   bool FLAG = false;
   for(int i=0;i<V;++i)
   {
           visited[i] = true;
           for(int j=0;j<adj[i].size();++j)
           {
               FLAG = isCyclic_util(adj,visited,adj[i][j]);
               if(FLAG==true)
                   return true;
           }
           visited[i] = false;
   }
   return false;
}

*/


/*
it has error
//v is no of vertex, adj[] is the adjacency matrix
bool isCyclic(int v, vector<int> adj[])
{
    stack<int> st;
    st.push(0);

    vector<bool> visited(v, false);
    vector<bool> ifparent(v, false);
    int flag= 0;

    int s;
    while(!st.empty()){
        s= st.top();
        ifparent[s]= true;
        visited[s]=true;
        flag=0;

        for(auto i: adj[s]){
            if(visited[i]){
                if(ifparent[i])
                    return true;
            }
            else if(!flag){
                st.push(i);
                flag= 1;
            }
        }

        if(!flag){
            ifparent[s]= false;
            st.pop();
        }
    }

    return false;

}
*/

bool isCyclic(int V, vector<int> adj[]) 
{
  vector<bool> visited (V, false);
  vector<bool> on_stack (V, false);
  stack<int> st;

  for (int w = 0; w < V; w++) {

    if (visited[w])
      continue;
    st.push(w);

    while (!st.empty()) {
      int s = st.top();

      if (!visited[s]) {
        visited[s] = true;
        on_stack[s] = true;
      } else {
        on_stack[s] = false;
        st.pop();
      }

      for (const auto &v : adj[s]) {
        if (!visited[v]) {
          st.push(v);
        } else if (on_stack[v]) {
          return true;
        }
      }
    }
  }
  return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends


