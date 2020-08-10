/*
Minimum Weighted Cycle
Problem Description

Given an integer A, representing number of vertices in a graph.

Also you are given a matrix of integers B of size N x 3 where N represents number of Edges in a Graph and Triplet (B[i][0], B[i][1], B[i][2]) implies there is an undirected edge between B[i][0] and B[i][1] and weight of that edge is

B[i][2].

Find and return the weight of minimum weighted cycle and if there is no cycle return -1 instead.

NOTE: Graph may contain multiple edges and self loops.



Problem Constraints
1 <= A <= 1000

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 100000



Input Format
The first argument given is the integer A.

The second argument given is the integer matrix B.



Output Format
Return the weight of minimum weighted cycle and if there is no cycle return -1 instead.



Example Input
Input 1:

 A = 4
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]
        [3 ,4 ,1]
        [4 ,1 ,4]
        [1 ,3 ,15]  ]
Input 2:

 A = 3
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]  ]


Example Output
Output 1:

 10 
Output 2:

 -1


Example Explanation
Explanation 1:

 Given graph forms 3 cycles
 1. 1 ---> 2 ---> 3 ---> 4 ---> 1 weight = 10
 2. 1 ---> 2 ---> 3 ---> 1 weight = 20
 3. 1 ---> 3---> 4 ---> 1 weight = 20
 so answer would be 10.
Explanation 2:

 Given graph forms 0 cycles so return -1.
 
*/


#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
struct Edge
{
	int u;
	int v;
	int weight;
};

class Graph
{
	int V ;
	list < pair <int, int > > *adj;
	vector < Edge > edge;

public :
	Graph( int V )
	{
		this->V = V ;
		adj = new list < pair <int, int > >[V];
	}

	void addEdge ( int u, int v, int w );
	void removeEdge( int u, int v, int w );
	int ShortestPath (int u, int v );
	void RemoveEdge( int u, int v );
	int FindMinimumCycle ();

};
void Graph :: addEdge ( int u, int v, int w )
{
	adj[u].push_back( make_pair( v, w ));
	adj[v].push_back( make_pair( u, w ));
	Edge e { u, v, w };
	edge.push_back ( e );
}
void Graph :: removeEdge ( int u, int v, int w )
{
	adj[u].remove(make_pair( v, w ));
	adj[v].remove(make_pair(u, w ));
}
int Graph :: ShortestPath ( int u, int v )
{
	set< pair<int, int> > setds;
	vector<int> dist(V, INF);

	setds.insert(make_pair(0, u));
	dist[u] = 0;

	while (!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}
	return dist[v] ;
}
int Graph :: FindMinimumCycle ( )
{
	int min_cycle = INT_MAX;
	int E = edge.size();
	for ( int i = 0 ; i < E ; i++ )
	{
		Edge e = edge[i];

		removeEdge( e.u, e.v, e.weight ) ;
		int vistance = ShortestPath( e.u, e.v );
		min_cycle = min( min_cycle, vistance + e.weight );
	addEdge( e.u, e.v, e.weight );
	}
	return min_cycle ;
}
int Solution::solve(int A, vector< vector <int> > &B) {
    Graph g(A);
	int E=B.size();
	for(int i=0;i<E;i++)
    {
        B[i][0]--;
        B[i][1]--;
    g.addEdge(B[i][0],B[i][1],B[i][2]);
    }
    return g.FindMinimumCycle();
}


/*
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
struct Edge
{
	int u;
	int v;
	int weight;
};

class Graph
{
	int V ;
	list < pair <int, int > > *adj;
	vector < Edge > edge;

public :
	Graph( int V )
	{
		this->V = V ;
		adj = new list < pair <int, int > >[V];
	}

	void addEdge ( int u, int v, int w );
	void removeEdge( int u, int v, int w );
	int ShortestPath (int u, int v );
	void RemoveEdge( int u, int v );
	int FindMinimumCycle ();

};
void Graph :: addEdge ( int u, int v, int w )
{
	adj[u].push_back( make_pair( v, w ));
	adj[v].push_back( make_pair( u, w ));
	Edge e { u, v, w };
	edge.push_back ( e );
}
void Graph :: removeEdge ( int u, int v, int w )
{
	adj[u].remove(make_pair( v, w ));
	adj[v].remove(make_pair(u, w ));
}
int Graph :: ShortestPath ( int u, int v )
{
	set< pair<int, int> > setds;
	vector<int> dist(V, INF);

	setds.insert(make_pair(0, u));
	dist[u] = 0;

	while (!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}
	if(dist[v]==INF)return -1;
	return dist[v] ;
}
int Graph :: FindMinimumCycle ( )
{
	int min_cycle = INF;
	int E = edge.size();
	for ( int i = 0 ; i < E ; i++ )
	{
		Edge e = edge[i];

		removeEdge( e.u, e.v, e.weight ) ;
		int vistance = ShortestPath( e.u, e.v );
		if(vistance==-1)continue;
		min_cycle = min( min_cycle, vistance + e.weight );
	addEdge( e.u, e.v, e.weight );
	}
	if(min_cycle==INF)min_cycle=-1;
	return min_cycle ;
}
int Solution::solve(int A, vector< vector <int> > &B) {
    Graph g(A);
	int E=B.size();
	for(int i=0;i<E;i++)
    {
        B[i][0]--;
        B[i][1]--;
    g.addEdge(B[i][0],B[i][1],B[i][2]);
    }
    return g.FindMinimumCycle();
}
*/

