/*
Implementing Dijkstra | Set 1 (Adjacency Matrix) 
Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix and in the next line are V*V space-separated values, which denote the weight of an edge of the matrix (gr[i][j] represents the weight of an edge from ith node to jth node). The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test, case output will be V space-separated integers where the ith integer denotes the shortest distance of the ith vertex from source vertex.

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra() which takes the adjacency matrix of the Graph g, the source vertex src and the number of vertices V as inputs and returns a list containing the minimum distance of all the vertices from the source vertex.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 20 
1 <= V <= 100
0 <= graph[i][j] <= 1000
0 <= s < V

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.

Note:
You must assume that graph[i][j] = 0 means that the path from i to j does not exist.
 
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/



vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
     // Your code here
    priority_queue < pair<int,int> , 
    vector<pair<int,int>> , 
    greater<pair<int,int>> > pq;
    
    vector<int>distance(V,INT_MAX);
    bool visited[V]={false};
    pq.push({0,src});
    distance[src]=0;
    
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int u=p.second;
        if(visited[u]==true) continue;
        visited[u]=true;
        for(int i=0;i<V;i++)
        {
            if(graph[u][i]!=0)
            {
                int v=i;    
                int wt=graph[u][i];
                if(distance[v]>distance[u]+wt)
                {
                    distance[v]=distance[u]+wt;
                    pq.push({distance[v],v});
                }
            }
        } 
    }
    for(int i=0;i<V;i++) cout<<distance[i]<<" ";
}

