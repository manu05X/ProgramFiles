/*
Minimum Difference

You are given a 2-D matrix C of size A × B.
You need to build a new 1-D array of size A by taking one element from each row of the 2-D matrix in such a way that the cost of the newly build array is minimized.

Cost of an array is the minimum possible value of the absolute difference between any two adjacent elements of the array.

So if the newly built array is X, element picked from row 1 will become X[1], element picked from row 2 will become X[2], and so on.

Determine the minimum cost of the newly build array.



Problem Constraints
2 <= A <= 1000
2 <= B <= 1000
1 <= C[i][j] <= 106



Input Format
The first argument is an integer A denoting number of rows in the 2-D array.
The second argument is an integer B denoting number of columns in the 2-D array.
The third argument is a 2-D array C of size A x B.



Output Format
Return an integer denoting the minimum cost of the newly build array.



Example Input
Input 1:

 A = 2
 B = 2
 C = [ [8, 4]
      [6, 8] ]
Input 2:

 A = 3
 B = 2
 C = [ [7, 3]
       [2, 1]
       [4, 9] ]


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 Newly build array : [8, 8]. The minimum cost will be 0 since the absolute difference will be 0(8-8).
Explanation 2:

 Newly build array : [3, 2, 4]. The minimum cost will be 1 since the minimum absolute difference will be 1(3 - 2).
 
*/

int Solution::solve(int A, int B, vector<vector<int> > &C) {
    int min_diff=INT_MAX;
    
    for(auto i=0;i<A-1;i++)
    {
        for(auto j=0;j<B;j++)
        {
            for(auto k=0;k<B;k++)
            {
            int ans=abs(C[i][j]-C[i+1][k]);
            min_diff=min(min_diff,ans);
            }
        }
    }
    return min_diff;
}


/*

int Solution::solve(int A, int B, vector<vector<int> > &C) {
    
    int x;
        int ans=1000000000;     // Initialize answer as a large number
        int lb;
        for(int i=0;i<A;i++)
        {
         sort(C[i].begin(),C[i].end());  // Sort each row of matrix
        }
        for(int i=0;i<A-1;i++)           
        {
            for(int j=0;j<B;j++)
            {
            lb=lower_bound(C[i+1].begin(),C[i+1].end(),C[i][j])-C[i+1].begin(); // check for next element as in soltion
            ans=min(ans,abs(C[i][j]-C[i+1][lb]));    // Update answer
            if(lb!=0)
             {
             ans=min(ans,abs(C[i][j]-C[i+1][lb-1]));
             }
            }
        }
    
        return ans;
}




class Solution:
    def solve(self, A, B, C):
        for lst in C:
            lst.sort()
        ans=1000009
        for i in range(0,A-1):
            for j in range(0,B):
                ele=C[i][j]
                x=bisect_left(C[i+1],ele)
                if(x!=B):
                    ans=min(ans,C[i+1][x]-ele)
                if(x==0):
                    continue
                ans=min(ans,ele-C[i+1][x-1])
        return ans

*/
