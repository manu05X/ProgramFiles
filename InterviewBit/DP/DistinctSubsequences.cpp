/*
Distinct Subsequences

Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.

*/

/*
S: "rabbbit"
T: "rabbit"

rows: 6
cols: 7

__vla_expr0: 7
__vla_expr1: 8

dp: {
     {1, 1, 1, 1, 1, 1, 1, 1}, 
     {0, 1, 1, 1, 1, 1, 1, 1}, 
     {0, 0, 1, 1, 1, 1, 1, 1}, 
     {0, 0, 0, 1, 2, 3, 3, 3}, 
     {0, 0, 0, 0, 1, 3, 3, 3}, 
     {0, 0, 0, 0, 0, 0, 3, 3}, 
     {0, 0, 0, 0, 0, 0, 0, 3}
    }

Output: 3
*/


class Solution {
public:
    int numDistinct(string S, string T) {
        int rows = T.length();
        int cols = S.length();
        
        // vector<vector<long long>> temp(rows+1, vector<long long>(cols+1, 0));
        
        long long dp[rows+1][cols+1];


        if (rows > cols) 
            return 0;

        for(int i = 1; i <= rows; i++)
            dp[i][0] = 0;

        for(int j = 0; j <= cols; j++)
            dp[0][j] = 1;

        for(int i = 1; i <= rows; i++)
        {
            for(int j = 1; j <= cols; j++)
            {
                if(T[i-1]!=S[j-1])
                {
                    dp[i][j] = dp[i][j-1];
                }
                else
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])% 1000000007;
            }
        }
        return dp[rows][cols];
    }
};


/*
int Solution::numDistinct(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> f(T.size()+1);

    //set the last size to 1.
    f[T.size()]=1;

    for(int i=S.size()-1; i>=0; --i){
        for(int j=0; j<T.size(); ++j){
            f[j]+=(S[i]==T[j])*f[j+1];
            // printf("%d\t", f[j] );
        }
        // cout<<"\n";
    }
    return f[0];
}
*/