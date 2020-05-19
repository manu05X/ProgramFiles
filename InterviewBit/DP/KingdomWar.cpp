/*
Kingdom War
Two kingdoms are on a war right now, kingdom X and kingdom Y. As a war specialist of kingdom X, you scouted kingdom Y area.

A kingdom area is defined as a N x M grid with each cell denoting a village.
Each cell has a value which denotes the strength of each corresponding village.
The strength can also be negative, representing those warriors of your kingdom who were held hostages.

There’s also another thing to be noticed.

The strength of any village on row larger than one (2<=r<=N) is stronger or equal to the strength of village which is exactly above it.
The strength of any village on column larger than one (2<=c<=M) is stronger or equal to the strength of vilage which is exactly to its left.
(stronger means having higher value as defined above).
So your task is, find the largest sum of strength that you can erase by bombing one sub-matrix in the grid.

Input format:

First line consists of 2 integers N and M denoting the number of rows and columns in the grid respectively.
The next N lines, consists of M integers each denoting the strength of each cell.

1 <= N <= 1500
1 <= M <= 1500
-200 <= Cell Strength <= 200
Output:

The largest sum of strength that you can get by choosing one sub-matrix.
Example:

Input:
3 3
-5 -4 -1
-3 2 4
2 5 8

Output:
19

Explanation:
Bomb the sub-matrix from (2,2) to (3,3): 2 + 4 + 5 + 8 = 19



*/

int Solution::solve(vector<vector<int> > &A) {
    int ans,i,j,dn,rig,r,c,sum;
    int n=A.size();
    int m=A[0].size();
    vector<vector<int> > rsum=A;
    for(r=0;r<n;r++)
    {
        for(c=m-2;c>=0;c--)
        {
            rsum[r][c]=A[r][c]+rsum[r][c+1];
        }
    }
    int ma=A[n-1][m-1];
    int dp[n][m];
    memset(dp,0,sizeof(dp));
    for(j=m-1;j>=0;j--)
    {
        for(i=n-1;i>=0;i--)
        {
            rig=0;
            dn=0;
            if(i!=n-1)
            {
                dn=dp[i+1][j];
            }
            if(j!=m-1)
            {
                rig=rsum[i][j+1];
            }
            dp[i][j]=A[i][j]+rig+dn;
            ma=max(ma,dp[i][j]);
        }
    }
    return(ma);
}


/*
int Solution::solve(vector<vector<int> > &A) {
    if(A.empty()) return 0;
    int m=A.size(),Max=0,n=A[0].size(),temp=A[0][0];
    int dp[n]={0};
    for(int i=m-1;i>=0;i--){
       for(int j=0;j<n;j++){
           dp[j]+=A[i][j];
           temp=max(A[i][j],temp);
       }
       int sum=0;
       for(int j=n-1;j>=0 and dp[j]>0;j--)
           sum+=dp[j];
       Max=max(sum,Max);
    }
    if(Max==0) Max=temp;
    return Max;
}

---------------------------------------------
int Solution::solve(vector<vector<int> > &A) {
    int dp[A.size()][A[0].size()];
    int m =A.size()-1;
    int n =A[0].size()-1;
    
    
    
    for(int i=m;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(i == m&& j == n){
                dp[i][j] = A[i][j];    
            } else if(i == m) {
                dp[i][j] = max(dp[i][j+1],dp[i][j+1]+A[i][j]);
            } else if(j == n) {
                dp[i][j] = max(dp[i+1][j],dp[i+1][j]+A[i][j]);
            } else {
                int k = max(dp[i+1][j+1],max(dp[i+1][j],dp[i][j+1]));
                dp[i][j] = max(k,dp[i+1][j]+dp[i][j+1] + A[i][j] - dp[i+1][j+1]);
            }
        }
    }
    
    return dp[0][0];
}
*/