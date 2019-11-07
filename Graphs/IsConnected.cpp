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
