/*
https://leetcode.com/problems/cherry-pickup/
741. Cherry Pickup
# like min path sum and Dungeon Game
*/


class Solution {
public:
    int dp[50][50][50];
    vector<vector<int>> grid;
    int helper(int r1, int c1, int c2, int N)
    {
        int r2 = r1+c1-c2;
        if(r1 >= N || r2 >= N || c1 >= N || c2 >= N || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;
        
        if(dp[r1][c1][c2] != -1) // if we already have ans
            return dp[r1][c1][c2];
        
        if(r1 == N-1 && c1 == N-1)// final pos is reached
            return grid[r1][c1];
        
        int ans = grid[r1][c1];
        if(c1 != c2)            // Position of 2 people is diffrent
            ans += grid[r2][c2];
        
        // max of all 4 transition [(r,r),(d,r),(r,d),(d,d)]
        int temp = max(helper(r1,c1+1,c2+1,N),helper(r1+1,c1,c2+1,N));
        temp = max(temp, helper(r1,c1+1,c2,N));
        temp = max(temp, helper(r1+1,c1,c2,N));
        
        ans += temp;
        
        return dp[r1][c1][c2] = ans;
        
    }
    
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        grid = g;
        
        memset(dp,-1,sizeof(dp));
        return max(0,helper(0,0,0,n));
    }
};