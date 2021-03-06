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

/*
This problem is equivalent to detecting a cycle in the directed graph represented by prerequisites. Both BFS and DFS can be used to solve it using the idea of topological sort. Since pair<int, int> is inconvenient for implementing graph algorithms, we first transform it to the adjacency-list representation. If course u is a prerequisite of course v, then the adjacency list of u will contain v.

BFS

BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of its neighbors by 1. This process will be repeated for n (number of nodes) times.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};
DFS

For DFS, in each visit, we start from a node and keep visiting its neighbors, if at a time we return to a visited node, there is a cycle. Otherwise, start again from another unvisited node and repeat this process. We use todo and done for nodes to visit and visited nodes.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return false;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int v : g[node]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
};
*/

