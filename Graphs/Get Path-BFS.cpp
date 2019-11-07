#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int>* getPath_BSF(int **edges, int n, int sv, int ev)
{
    queue<int> bfsq;
    bool *visited = new bool[n];
    for(int i=0; i < n; i++)
    {
        visited[i]= false;
    }
    
    bfsq.push( sv );
    visited[sv] = true;
    
    bool done = false ;// flage variable
    unordered_map<int,int> parent;
        
    while(!bfsq.empty() && !done)
    {
        int front = bfsq.front();
        bfsq.pop();
        
        for(int i=0; i < n; i++)
        {
            if(edges[front][i] && !visited[i])
            {
                parent[i] = front;
        
                bfsq.push(i);
                visited[i] = true;
                
                if(i == ev)
                {
                    done = true;
                    break;
                }
            }
        }
    }
    delete [] visited;
    
    if(!done)
    {
        return NULL;
    }else{
        vector<int>* output = new vector<int>();
        int current = ev;
        output ->push_back(ev);
        
        while(current != sv)
        {
            current = parent[current];
            output->push_back(current);
        }
        return output;
    }
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
    
    int sv,ev;
        cin >> sv >> ev;
        vector<int>* output = getPath_BSF(edges, n, sv, ev);
        if(output !=NULL)
        {
            //cout <<"PATH"<<endl;
            for(int i=0; i< output->size(); i++)
            {
                cout << output->at(i) <<" ";
            }
            delete output;
        }
    
    for(int i=0; i < n; i++)
    {
        delete []edges[i];
    }
    delete [] edges;
   //return 0;
 }
