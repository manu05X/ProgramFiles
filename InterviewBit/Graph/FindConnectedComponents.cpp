/*
Find Connected Components
0 -> 4 8 13 14 
1 -> 5 
2 -> 9 15 
3 -> 9 
4 -> 0 8 
5 -> 1 16 17 
6 -> 7 11 
7 -> 6 11 
8 -> 0 4 
9 -> 2 3 15 
10 -> 15 
11 -> 6 7 
12 -> 
13 -> 0 14 
14 -> 0 8 13 
15 -> 2 9 10 
16 -> 5 
17 -> 5 

There are 5 components in the graph

0 -> [0 4 8 13 14 ]

1 -> [1 5 16 17 ]

2 -> [2 3 9 10 15 ]

3 -> [6 7 11 ]

4 -> [12 ]


*/

#include <iostream>
#include <vector>

using namespace std;

void printGraph(vector<vector<int> >& g) {
  for (int i = 0; i < g.size(); i++) {
    cout << i << " -> ";
    for (int j = 0; j < g[i].size(); j++) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
}

void dfs(int at, vector<vector<int> >& g, int& count, vector<int>& components, vector<int>& visited) {
  if (visited[at]) {
    return;
  }

  visited[at] = true;
  components[at] = count;
  vector<int> neighbours = g[at];
  for (int i = 0; i < neighbours.size(); i++) {
    dfs(neighbours[i], g, count, components, visited);
  }
}

void findConnectedComponents(
  int N,
  vector<vector<int> >& g,
  int& count,
  vector<int>& components,
  vector<int>& visited
) {
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      dfs(i, g, count, components, visited);
      count++;
    }
  }
}

int main() {
  int n = 18;
  vector<vector<int> > graph(n, vector<int>(0));
  graph[0].push_back(4);
  graph[0].push_back(8);
  graph[0].push_back(13);
  graph[0].push_back(14);
  graph[1].push_back(5);
  graph[2].push_back(9);
  graph[2].push_back(15);
  graph[3].push_back(9);
  graph[4].push_back(0);
  graph[4].push_back(8);
  graph[5].push_back(1);
  graph[5].push_back(16);
  graph[5].push_back(17);
  graph[6].push_back(7);
  graph[6].push_back(11);
  graph[7].push_back(6);
  graph[7].push_back(11);
  graph[8].push_back(0);
  graph[8].push_back(4);
  graph[9].push_back(2);
  graph[9].push_back(3);
  graph[9].push_back(15);
  graph[10].push_back(15);
  graph[11].push_back(6);
  graph[11].push_back(7);
  graph[13].push_back(0);
  graph[13].push_back(14);
  graph[14].push_back(0);
  graph[14].push_back(8);
  graph[14].push_back(13);
  graph[15].push_back(2);
  graph[15].push_back(9);
  graph[15].push_back(10);
  graph[16].push_back(5);
  graph[17].push_back(5);
  printGraph(graph);
  int count = 0;
  vector<int> components(n, -1);
  vector<int> visited(n, false);
  findConnectedComponents(n, graph, count, components, visited);
  cout << "\nThere are " << count << " components in the graph" << endl;
  vector<vector<int> > finalColored(count, vector<int>(0));
  for (int i = 0; i < n; i++) {
    finalColored[components[i]].push_back(i);
  }
  for (int i = 0; i < count; i++) {
    cout << "\n" << i << " -> [";
    for (int j = 0; j < finalColored[i].size(); j++) {
      cout << finalColored[i][j] << " ";
    }
    cout << "]" << endl;
  }
  return 0;
}