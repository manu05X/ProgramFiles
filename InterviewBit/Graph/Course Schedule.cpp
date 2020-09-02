/*

https://leetcode.com/problems/course-schedule/
207. Course Schedule


*/
// using DFS algo

class Solution {
    bool isCyclic(vector<vector<int>>& adj,vector<int>& visited,int curr)
    {
        /* base case: if we visit a node (2 = processing) which is 
        already processing return true as cycle is present */
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2; // make curr node processing =2
        for(int i=0;i<adj[curr].size();++i)
        {
            if(visited[adj[curr][i]]!=1) // already processed node = 1 
            {
                if(isCyclic(adj,visited,adj[curr][i]) == true)
                    return true;
            }
        }
        // after processing all adjecent node make curr node processed i.e 1
        visited[curr] = 1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<vector<int>> adj(numCourses);
        //Make adjacency matrix (Directed graph)
        for(int i=0;i<prerequisites.size();++i)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
       // initializing visited arry of 3 state 0 = unvisited,1 = processed,2 = processing 
        vector<int> visited(numCourses,0);
        // traversing each node to see if cycle is present or not
        for(int i=0;i<numCourses;++i)
            if(visited[i]==0)
            {
                // if cycle present return false as dedlock is present
                if(isCyclic(adj,visited,i) == true)
                    return false;
            }
        // return true if no cycle is present after processing each node
        return true; // return false as no cycle present
    }
};