//https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/submissions/
//1130. Minimum Cost Tree From Leaf Values
/*
Approach :

Approach towards the solution is to partition the leaf nodes at all possible places, calculate the cost for each partition and return the minimum sum of both part.

Non-leaf cost from any subarray from i to j (product of two maximum val) is always same. No matter how you partition the subarray.

We split the leaf nodes Ai, Ai+1, ..... , Aj-1, Aj between Ak and Ak+1 where i<k<j then compute the sub problem for Ai, .... , Ak and Ak+1, ... , Aj and add both result plus the cost of multiplying two largest value in Ai, ... , Aj.

         leaf nodes :  [3,4,2,5,3,7]
         We can partition it in following ways:
         [3] | [4,2,5,3,7]
         [3,4] | [2,5,3,7]
         [3,4,2] | [5,3,7]
         [3,4,2,5] | [3,7]
         [3,4,2,5,3] | [7]
Since we can see overlapping subproblems easily.
1. [3,4] | [2,5,3,7] ---> [3,4] || [2] | [5,3,7]
2. [3,4,2] | [5,3,7] 

[5,3,7] is example of overlapping subproblem.


//https://youtu.be/XHjjIJxnAJY
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,0,n-1,dp);
    }
    
    int solve(vector<int>&arr, int low, int high,vector<vector<int>> &dp){
        // if we have a single leaf node, then smallest possible sum
        // of non-leaf node is zero.
        if(low == high) return 0;
        
        // dp[i][j] --> smallest possible sum of value of each non-leaf node of
        // subarray from i to j both inclusive
        if(dp[low][high] != -1) return dp[low][high];
        
        // priority_queue is being used to find two max values in range [i...j]
        priority_queue<int> pq(arr.begin()+low, arr.begin()+high+1);
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
		
        // maxProduct hold product of two maximum values in given range
        int maxProduct = a*b;
        
        int minSum = INT_MAX;
        for(int i=low; i<high; i++){
            minSum = min(minSum, solve(arr,low,i,dp) + solve(arr,i+1,high,dp));
        }
        return dp[low][high] = minSum + maxProduct;
    }
};