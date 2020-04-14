/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
"true" or "false"
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*/

#include <bits/stdc++.h>

using namespace std;

void marker(int** edges, int n, int* visited, int sv){
	if (n==1)
	{
		visited[sv] = 1;
		return;
	}

	visited[sv] = 1;

	for (int i = 0; i < n; ++i)
	{
		if (edges[sv][i]==1 && visited[i]==0)
		{
			marker(edges, n, visited, i);
		}
	}
	return;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, e;
	cin>>n>>e;

	int** edges = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}

	}

	int* visited = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin>>a>>b;

		edges[a][b] = 1;
		edges[b][a] = 1;
	}


	marker(edges, n, visited, 0);

	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == 0)
		{
			cout << "false" << '\n';
			return 0;
		}

	}
	cout << "true" << '\n';
	

	return 0 ; 



}

/*
#include <iostream>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void DFS(unordered_map<int, vector<int>*>&adjacencyList, int v1, unordered_map<int,bool> &visited)
{
    vector<int> *adjacencyVertices = adjacencyList[v1];
    // mark it visited to avoid calling over this vertex again
    visited[v1] = true; 
    // Recursive Call
    for(int i=0; i < adjacencyVertices->size(); i++)
    {
        if(visited.count(adjacencyVertices-> at(i)) == 0)
        {
            DFS(adjacencyList, adjacencyVertices -> at(i), visited);
        
        }
    }
}

bool isConnected(unordered_map<int, vector<int>*> &adjacencyList)
{
    unordered_map<int, bool> visited;
    int sv = adjacencyList.begin()->first;
    DFS(adjacencyList,sv,visited);
    return visited.size() == adjacencyList.size();
}

int main() 
{
    int n, e;
    cin >> n >> e;
    
    unordered_map<int, vector<int>*> adjacencyList;
    for(int i=0; i < n; i++)
    {
        vector<int> *v =new vector<int>;
        adjacencyList[i]=v;
    }
    
    int count =1;
    while(count <= e)
    {
        int source, dest;
        cin >> source >>dest;
        adjacencyList[source]-> push_back(dest);
        adjacencyList[dest]->push_back(source);
        count++;
    }
    
    if(isConnected(adjacencyList))
    {
        cout << "true" <<endl;
    }
    else
    {
        cout<< "false" <<endl;
    }

 return 0;
}

*/