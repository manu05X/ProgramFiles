/*
Flip Array
Problem Description

Given an array A of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible).

Return the minimum number of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.



Problem Constraints
1 <= length of(A) <= 100

Sum of all the elements will not exceed 10,000.



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the minimum number of elements whose sign needs to be flipped.



Example Input
Input 1:

 A = [15, 10, 6]
Input 2:

 A = [14, 10, 4]


Example Output
Output 1:

 1
Output 2:

 1


Example Explanation
Explanation 1:

 Here, we will flip the sign of 15 and the resultant sum will be 1.
Explanation 2:

 Here, we will flip the sign of 14 and the resultant sum will be 0.
 Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there sign are not minimum.

*/


int Solution::solve(const vector<int> &A) {
    int n=A.size();
    int sum=0;
    for(int i=0;i<A.size();i++)
        sum=sum+A[i];
    //int sum= accumulate(A.begin(),A.end(),0);
    
    vector<vector<pair<int,int>>> dp((sum/2)+1,vector<pair<int,int>>(n+1,{0,0}));
    
    for(int i=1;i<=sum/2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[j-1]>i)
                dp[i][j]=dp[i][j-1];
            else
            {
                pair<int,int>incl{dp[i-A[j-1]][j-1].first +A[j-1],1+dp[i-A[j-1]][j-1].second};
                pair<int,int>excl{dp[i][j-1].first,dp[i][j-1].second};
                
                auto comp=[](const pair<int,int>& a,const pair<int,int>&b)
                {
                    if(a.first==b.first)
                    {
                        return a.second<b.second;
                    }
                    return a.first>b.first;
                };
                dp[i][j]=min(incl,excl,comp);
            }
                
        }
    }
    return dp[sum/2][n].second;
}
