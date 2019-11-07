#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void ConnectedComponent(unordered_map<int, vector<int>*> &adjacencyList, unordered_map<int, bool> &visited, vector<int> *smallOutput, int v)
{
    smallOutput ->push_back(v);
    visited[v] = true;
    
    vector<int> *adjvertices = adjacencyList[v];
    for(int i = 0; i < adjvertices ->size(); i++)
    {
        if(visited.count(adjvertices->at(i)) == 0)
        {
            ConnectedComponent(adjacencyList, visited, smallOutput, adjvertices->at(i));
        }
    }
}


vector<vector<int>*>* allconnectedComponent(unordered_map<int, vector<int>*> &adjacencyList)
{
    unordered_map<int, bool> visited;
    vector<vector<int>*> *output = new vector<vector<int>*>;
    int i = 0;
    while(visited.size()!= adjacencyList.size())
    {
        for(;i < adjacencyList.size(); i++)
        {
            if(visited.count(i) == 0)
            {
                vector<int> *smallOutput = new vector<int>;
                ConnectedComponent(adjacencyList, visited, smallOutput, i);
                output-> push_back(smallOutput);
            }
        }
    }
    return output;
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
    
    int count = 1;
    while(count <= e)
    {
        int source, dest;
        cin >> source >>dest;
        adjacencyList[source]-> push_back(dest);
        adjacencyList[dest]->push_back(source);
        count++;
    }
    
    vector<vector<int>*> *output = allconnectedComponent(adjacencyList);
    for(int i= 0; i < output->size(); i++)
    {
        vector<int> *component = output-> at(i);
        sort(component->begin(), component->end());
        for(int j= 0; j < component->size(); j++)
        {
            cout << component->at(j) <<" ";
        }
        cout << endl;
    }
    return 0;
}
    
