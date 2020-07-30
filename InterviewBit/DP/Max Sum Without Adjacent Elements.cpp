/*
Max Sum Without Adjacent Elements
Problem Description

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.



Problem Constraints
1 <= N <= 20000
1 <= A[i] <= 2000



Input Format
The first and the only argument of input contains a 2d matrix, A.



Output Format
Return an integer, representing the maximum possible sum.



Example Input
Input 1:

 A = [   
        [1]
        [2]    
     ]
Input 2:

 A = [   
        [1, 2, 3, 4]
        [2, 3, 4, 5]    
     ]


Example Output
Output 1:

 2
Output 2:

 8


Example Explanation
Explanation 1:

 We will choose 2.
Explanation 2:

 We will choose 3 and 5.
*/

int Solution::adjacent(vector<vector<int> > &A) {
    if(A.size()==0)
        return 0;

int include=0,exclude=0;

for(int i=0;i<A[0].size();i++)
{
    int num=max(A[0][i],A[1][i]);
    int temp=max(exclude,include);
    
    include=exclude+num;
    exclude=temp;
}
return max(include,exclude);
}
}

/*
int Solution::adjacent(vector<vector<int> > &V) {

    assert(V.size() == 2 && V.size() <= 20000);
    int N = V[0].size();
    
    int MAXSUM[N + 1][2];
    memset(MAXSUM, 0, sizeof(MAXSUM));

    int ele = max(V[0][0], V[1][0]);
    MAXSUM[0][1] = ele;
    for (int i = 1; i < N; i++) {
        
        // take the maximum of both the element in the current column.
        int cur_element = max(V[0][i], V[1][i]);
        
        // Case 1: Do not include current element.
        MAXSUM[i][0] = max(MAXSUM[i-1][0], MAXSUM[i-1][1]);
        
        // Case 2: Include current element
        MAXSUM[i][1] = cur_element + MAXSUM[i-1][0];
    }
    return max(MAXSUM[N-1][0], MAXSUM[N-1][1]);
}

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
JAVA:
public class Solution {
	public int adjacent(ArrayList<ArrayList<Integer>> A) {
	    
	    int n;
	    int dp[];
	    ArrayList<Integer> first, second;
	    first = A.get(0);
	    second = A.get(1);
	    
	    n = A.get(0).size();
	    
	    if (n == 0)
	        return 0;
	    
	    dp = new int[n];
	    dp[0] = Math.max(first.get(0), second.get(0));
	    
	    if (n < 2)
	        return dp[0];
	    
	    dp[1] = Math.max(first.get(1), second.get(1));
	    dp[1] = Math.max(dp[0], dp[1]);
	    
	    for (int i = 2; i < n; i++) {
	        dp[i] = Math.max(first.get(i), second.get(i));
	        dp[i] += dp[i - 2];
	        dp[i] = Math.max(dp[i], dp[i - 1]);
	    }
	    
	    return dp[n - 1];
	}
}
*/