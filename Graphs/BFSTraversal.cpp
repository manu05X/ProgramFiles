#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printBSF(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for(int i=0; i < n; i++)
    {
        visited[i]= false;
    }
    
    pendingVertices.push( sv );
    visited[sv] = true;
    
    while(!pendingVertices.empty())
    {
        int currVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currVertex <<" ";
        for(int i=0; i < n; i++)
        {
            if(i == currVertex)
            {
                continue;
            }
            if(edges[currVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
}

int main() 
{
    int n, e;
    cin >> n >> e;

    int** edges =new int*[n];
    for(int i=0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j < n; j++)
        {
            edges[i][j]=0;  //
        }
    }
        
    for(int i=0; i < e; i++)
        {
            int f, s;
            cin >> f >>s;
            edges[f][s]=1;
            edges[s][f]=1;
        }
        
        bool *visited =new bool[n];
        for(int i=0; i < n; i++)
        {
            visited[i] = false;
        }
        
       // cout <<"BSF"<<endl;
         printBSF(edges, n , 0) ;
    
    delete []visited;
    for(int i=0; i < n; i++)
    {
        delete []edges[i];
    }
    delete [] edges;

 return 0;
}
