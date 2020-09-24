/*
https://leetcode.com/problems/network-delay-time/
743. Network Delay Time
*/

#include<bits/stdc++.h>
using namespace std;


/* Function to do BFS of graph

adj : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

//M1 BFS(ripple effect)
class Solution {
    struct node{
        int dst;
        int wt;
    };
    struct qnode{
        int vertex;
        int dist;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int,vector<node *>> adj;
        // adjList formation
        for(int i=0;i<times.size();++i)
        {
            node *newnode = new node;
            newnode->dst = times[i][1];
            newnode->wt = times[i][2];
            adj[times[i][0]].push_back(newnode);
        }
        
        qnode *qn = new qnode;
        qn->vertex = K;    //Initial vertex is K
        qn->dist = 0;       //Source distance is 0
        queue<qnode *> q;   // Initilizing queue
        q.push(qn);
        
        vector<int> distance(N+1,INT_MAX);
        distance[K] = 0;
        int time = 0;
        
        while(!q.empty())   //BFS
        {
            qnode *curr = q.front();
            q.pop();
            
            for(auto it: adj[curr->vertex])
            {
                qnode *temp_qn = new qnode;
                temp_qn->vertex = it->dst;
                temp_qn->dist = it->wt + curr->dist;
                if(distance[temp_qn->vertex] > temp_qn->dist)   
                {
                    // updating the distance value if condition satisfy
                    q.push(temp_qn);
                    distance[temp_qn->vertex] = it->wt + curr->dist;
                }
            }
        }
        //STEP-2: Find the max distance node (If all the nodes are traversed)
        for(int i=1;i<=N;++i)
        {
            if(distance[i]==INT_MAX)
                return -1;
            time = max(time,distance[i]);
        }
        return time;
    }
};


//M2 Dijkstra Algo

typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pii>>vp(N+1);
        for(const auto&time:times)    vp[time[0]].emplace_back(time[1],time[2]);
        vector<bool>visited(N+1,false);
        vector<int>d(N+1,INT_MAX);
        d[0]=0,d[K]=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.emplace(0,K);
        while(!pq.empty()){
            auto [c,u] = pq.top();
            pq.pop();
            if(visited[u]) continue;
            for(auto to:vp[u]){
                auto[v,w]=to;
                if(c+w<d[v])    {
                    d[v]=c+w;
                    pq.emplace(d[v],v);
                }
            }
            visited[u]=true;
        }
        int res = *max_element(begin(d),end(d));
        return res==INT_MAX?-1:res;
    }
};