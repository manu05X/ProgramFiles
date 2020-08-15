/*
c 
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Input:
The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers V (number of vertices) and E (number of edges). In the next line are E space separated values u,v denoting an edge from u to v.

Output: For each testcase return the mother vertex of graph (if exists) else return -1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMother() which takes a Directed graph and the number of vertices as inputs and returns a Mother Vertex in the Graph. If the graph has multiple Mother Vertices, return the one with the smallest value. If the Mother Vertex does not exist, return -1.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 500
1 <= V <= 500
1 <= E <= 3000
0 <= u, v < N

Example:
Input:
2
5 5
1 0 0 2 2 1 0 3 3 4
3 2
0 1 2 1

Ouput:
0
-1

Explanation:
Testcase 1: According to the given edges, all nodes can be reaced from nodes from 0, 1 and 2. But, since we are traversing from node 0, so 0 is the output.

Testcase 2: According to the given edges, no vertices are there from where we can reach all vertices. So, output is -1.

 
*/

// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * g[]: graph representation
 */

 //int count;
void dfs(int i,vector<int> g[],vector<int> &vis)
 {
    if(vis[i]){return;}
    vis[i]=1;
    for(auto u:g[i])
    {
        if(!vis[u])
        {
            dfs(u,g,vis);
        }
    }
     
 }

int findMother(int v, vector<int> g[]) 
{ 
    // Your code here
   int last_vis_node;
    
   vector<int> vis(v,0);
    for(int i=0;i<v;i++)//dfs of all nodes;
    {   
        if(!vis[i])
        {
            dfs(i,g,vis);
            
            last_vis_node= i; 
        }
    }
    vis.clear();
    vis.resize(v);
    dfs(last_vis_node,g,vis);
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            return -1;
        }
    }
    return (last_vis_node);
    
    
} 


// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends


/*
*ArrayList<ArrayList<Integer>> list: arraylist of arraylist which represents graph
*n: represents number of vertex in graph

class MotherVertex
{
    static boolean dfs(ArrayList<ArrayList<Integer>> list,int n,int src)
    {
        boolean vis[] = new boolean[n];
        int count = 0;
        Stack<Integer> s = new Stack<Integer>();
        s.add(src);
        vis[src] = true;
        while(!s.isEmpty())
        {
            int p = s.pop();
            count++;
            ArrayList<Integer> e = list.get(p);
            for(int i=e.size()-1;i>=0;i--)
            {   
                int j = e.get(i);
                if(!vis[j])
                {
                    s.add(j);
                    vis[j] = true;
                }
            }
        }
        if(count == n)  return true;
        
        return false;
    }
    static int findMother(ArrayList<ArrayList<Integer>> list, int n)
    {
        for(int i=0;i<n;i++)
        {
            if(dfs(list,n,i))
                return i;
        }
        return -1;
    }
    
}

*/

