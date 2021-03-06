// https://leetcode.com/problems/triangle/
// Triangle


/*

SImple step by step Recursive -> Memoization -> DP three solutions || easy to understand

Here is three solution Recursive -> Memoization -> DP
Step By Step.

1.Recursive (It may give TLE , but good understanding of memoization and dp you should understand it first)

42 / 43 test cases passed.

*/
class Solution {
public:
   int minTotalUtil(vector<vector<int>>& triangle, int h, int j) {
        
       if(h == triangle.size() || j>=triangle[h].size()) {
             return 0;
        }  
        
        return triangle[h][j]+min(minTotalUtil(triangle, h+1, j),minTotalUtil(triangle, h+1, j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         
          return minTotalUtil(triangle, 0, 0);
    }
};

/*
2. Memoization of recursive solution :

Runtime: 12 ms
Memory Usage: 8.9 MB
*/

class Solution {
public:
   int minTotalUtil(vector<vector<int>>& triangle, int h, int j,vector<vector<int>> &v) {
        if(h == triangle.size() || j>=triangle[h].size()) {
             
            return 0;
        }
         if(v[h][j]!=-1) return v[h][j];  
        
        return v[h][j]=triangle[h][j]+min(minTotalUtil(triangle, h+1, j,v),minTotalUtil(triangle, h+1, j+1,v));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
          int h=triangle.size(),j;
         j=h;
        vector<vector<int>> v(h,vector<int> (j,-1));
          minSum=minTotalUtil(triangle, 0, 0,v);
        
        cout << minSum << endl;
        return minSum;
        
    }
};

/*
3. Last and best DP

Runtime: 8 ms
Memory Usage: 8.8 MB
*/

 class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int minSum = INT_MAX;
          int h=triangle.size(),j;
         j=h;
        vector<vector<int>> v(h,vector<int> (j,0));
         v[0][0]=triangle[0][0];
         for(int i=1;i<h;i++)
         {
             for(int j=0;j<triangle[i].size();j++)
             {
                 if(j==0) v[i][j]=v[i-1][j]+triangle[i][j];
                 else if(j==triangle[i].size()-1) v[i][j]=v[i-1][j-1]+triangle[i][j];
                 else
                 v[i][j]=min(v[i-1][j-1],v[i-1][j])+triangle[i][j];
             }
              
         }
         
        return *min_element(v[h-1].begin(),v[h-1].end());
         
        
    }
};

/*
Or you can refer this also

Runtime: 16 ms
Memory Usage: 8.5 MB
*/
/**/
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& tri) {
          int h=tri.size();
         for(int i=1;i<tri.size();i++)
         {
             for(int j=0;j<tri[i].size();j++)
             {
                 if(j==0) tri[i][j]=tri[i-1][j]+tri[i][j];
                 else if(j==tri[i].size()-1) tri[i][j]=tri[i-1][j-1]+tri[i][j];
                 else
                 tri[i][j]=min(tri[i-1][j-1],tri[i-1][j])+tri[i][j];
             }
              
         }
         
        return *min_element(tri[h-1].begin(),tri[h-1].end());
         
        
    }
};