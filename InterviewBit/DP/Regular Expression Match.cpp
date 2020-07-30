/*
Regular Expression Match
Problem Description

Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

' ? ' : Matches any single character.
' * ' : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Problem Constraints
1 <= length(A), length(B) <= 104



Input Format
The first argument of input contains a string A.
The second argument of input contains a string B.



Output Format
Return 1 if the patterns match else return 0.



Example Input
Input 1:

 A = "aaa"
 B = "a*"
Input 2:

 A = "acz"
 B = "a?a"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Since '*' matches any sequence of characters. Last two 'a' in string A will be match by '*'.
 So, the pattern matches we return 1.
Explanation 2:

 '?' matches any single character. First two character in string A will be match. 
 But the last character i.e 'z' != 'a'. Return 0.
 
*/

int Solution::isMatch(const string A, const string B) {
    int n = A.size();
    int m = B.size();
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(B[i] == '*'){
            cnt++;
        }
    }
    if((m - cnt) > n)
        return 0;
    int DP[n+1];
    memset(DP,0,sizeof(DP));
    DP[0] = 1;
    for(int i = 0; i < m; i++){
        if (B[i] == '*'){
            for(int j = 1; j <= n; j++){
                DP[j] = (DP[j-1] || DP[j]);
            }
        }
        else{
            for(int j = n-1; j >= 0; j--){
                DP[j+1] = DP[j] & (B[i] == A[j] || B[i] == '?');
            }
        }
        DP[0] = DP[0] & (B[i] == '*');
    }
    if(DP[n])
        return 1;
    return 0;
}

/*
public class Solution {
	public int isMatch(final String s, final String p) {
	    boolean[][] d = new boolean[s.length() + 1][p.length() + 1];
	    d[0][0] = true;
	    if (p.charAt(0) == '*') {
	        d[0][1] = true;
	    }
	    for (int i = 0; i < p.length(); ++i) {
	        if (p.charAt(i) == '*') {
	            d[0][i + 1] = d[0][i];
	            for (int j = 0; j < s.length(); ++j) {
	                d[j + 1][i + 1] = d[j][i] || d[j + 1][i] || d[j][i + 1];
	            }
	        } else if (p.charAt(i) == '?') {
	            for (int j = s.length() - 1; j >= 0; --j) {
	                d[j + 1][i + 1] = d[j][i];
	            }
	        } else {
	            for (int j = 0; j < s.length(); ++j) {
	                if (p.charAt(i) == s.charAt(j)) {
	                    d[j + 1][i + 1] = d[j][i];
	                }
	            }
	        }
	    }
	    return d[s.length()][p.length()] ? 1 : 0;
	}
}



*/
