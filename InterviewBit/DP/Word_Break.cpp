/*
Word Break
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Constraints:

1 <= len(A) <= 6500
1 <= len(B) <= 10000
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "myinterviewtrainer",
    B = ["trainer", "my", "interview"]

Output 1:
    1

Explanation 1:
    Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".

Input 2:
    A = "a"
    B = ["aaa"]

Output 2:
    0

Explanation 2:
    Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".
		
*/

int Solution::wordBreak(string A, vector<string> &B) {
    int N=A.length();
    int n=B.size();
    
    vector<bool> dp(N+1);
    dp[0]=1;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<n;j++)
        {
            int idx1=i;
            int idx2=B[j].length()-1;
            
            while(idx1 >=0 && idx2 >=0 && A[idx1]==B[j][idx2])
                idx1--,idx2--;
                
            if(idx2==-1)
                dp[i+1]=dp[idx1+1];
            if(dp[i+1])
                break;
        }
    }
    return dp[N];
}


/*
public class Solution {
	public int wordBreak(String s, ArrayList<String> B) {
        boolean[] t = new boolean[s.length()+1];
        t[0] = true; //set first to be true, why?
        //Because we need initial state
        Set<String> dict = new HashSet<>(B);
        for(int i=0; i<s.length(); i++){
            //should continue from match position
            if(!t[i]) 
                continue;
 
            for(String a: dict){
                int len = a.length();
                int end = i + len;
                if(end > s.length())
                    continue;
 
                if(t[end]) continue;
 
                if(s.substring(i, end).equals(a)){
                    t[end] = true;
                }
            }
        }
 
        return t[s.length()]?1:0;
    }
}
*/