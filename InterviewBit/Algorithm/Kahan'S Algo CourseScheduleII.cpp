
/*
https://leetcode.com/problems/course-schedule-ii/

210. Course Schedule II
*/


// Kahans Algorithm

class Solution {
    //Topological sort
    bool kahnsAlgo(vector<vector<int>>& adj,int n,vector<int>& indegree,vector<int>& ans)
    {
        //STEP-2: Take a queue and push all vertices with indegree = 0
        queue<int> q;
        for(int i=0;i < n; ++i)
            if(indegree[i] == 0)
                q.push(i);
        
        /*STEP-3: Process all the node with indegree 0 and keep decrementing other nodes indegree while processing*/
        
        int count = 0;  // keep count of no of processed nodes(for cycle detection in graph)
        while(q.empty() == false)
        {
            int curr = q.front();
            q.pop();
            
            //Decrement the indegree of all the adjecent vertices
            for(auto a: adj[curr])
            {
                indegree[a]-=1;
                if(indegree[a] == 0)
                    q.push(a);
            }
            
            ans.push_back(curr);    //Push current node (forms topological ordering)
            count+= 1;  //keep count of no of processed vertices
        }
        
        // No of processed node not equal to total nodes
        if(count != n)  
            return false;   //Graph is not a DAG
        return true;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);  // store indegree of each node
        
        //Make adjacecncy list
        for(int i=0;i<n;++i)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] += 1;   //STEP - 1
        }
        
        //  Kahn's Algorithm
        vector<int> ans;
        if(kahnsAlgo(adj,numCourses,indegree,ans))
            return ans;
        
        vector<int> empty;
        return empty;
    }
};