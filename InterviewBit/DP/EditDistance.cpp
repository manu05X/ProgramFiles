/*
Edit Distance

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.

*/

int Solution::minDistance(string A, string B) {
    int row = A.size();
    int col = B.size();
    
    vector<vector<int> > temp(row+1, vector<int>(col+1));
    
    for(int i = 0; i < temp.size(); i++){
        for(int j = 0; j < temp[0].size(); j++){
            if(j == 0){
                temp[i][j] = i;
            }
            else if(i == 0){
                temp[i][j] = j;
            }
            else if(A[i-1] == B[j-1]){
                temp[i][j] = temp[i-1][j-1];
            }
            else{
                temp[i][j] = min(temp[i-1][j-1], temp[i-1][j]);
                temp[i][j] = min(temp[i][j-1], temp[i][j]);
                temp[i][j] = temp[i][j]+1;
            }
        }
    }
    
    return temp[row][col];
}



/*
public class Solution {
    public int minDistance(String A, String B) {
        if (A == null && B == null) return 0;
        int m = A.length(), n = B.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        // dp[i][j] stands for the minimum distance for substring ending in i for String A and substring 
        // of B ending in j
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char chA = A.charAt(i);
                char chB = B.charAt(j);
                if (chA == chB)
                    dp[i + 1][j + 1] = dp[i][j];
                else {
                    dp[i + 1][j + 1] = min3(dp[i][j], dp[i + 1][j], dp[i][j + 1]) + 1;
                } 
            }
        }
        return dp[m][n];
        
    }
    
    private int min3(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }
}
*/