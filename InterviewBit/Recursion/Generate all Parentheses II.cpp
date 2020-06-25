/*
Generate all Parentheses II
Problem Description

Given an integer A pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*A.



Problem Constraints
1 <= A <= 20



Input Format
First and only argument is integer A.



Output Format
Return a sorted list of all possible paranthesis.



Example Input
Input 1:

A = 3
Input 2:

A = 1


Example Output
Output 1:

[ "((()))", "(()())", "(())()", "()(())", "()()()" ]
Output 2:

[ "()" ]


Example Explanation
Explanation 1:

 All paranthesis are given in the output list.
Explanation 2:

 All paranthesis are given in the output list.

*/

//sol->


void backtracking(int n,int open,int close,string str,vector<string>& res)
{
    if(close==n)
    {
        res.emplace_back(str);
        return;
    }
    else
    {
        if(open<n)
        {
            str+='(';
            backtracking(n,open+1,close,str,res);
            str.pop_back();
        }
        if(open>close)
        {
            str +=')';
            backtracking(n,open,close+1,str,res);
            str.pop_back();
        }
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string>res;
    
    if(A>0)
        backtracking(A,0,0,"",res);
    return res;
}







/*
public class Solution {
    
    private ArrayList<String> res;
    
	public ArrayList<String> generateParenthesis(int A) {
	    res = new ArrayList<>();
	    StringBuilder str = new StringBuilder();
	    rec(0, 0, 0, str, A);
	    return res;
	}
	
	public void rec(int leftCount, int rightCount, int index, StringBuilder str, int n) {
	    
	    if (leftCount > n || rightCount > n)
	        return;
	        
	    if (rightCount > leftCount)
	        return;
	    
	    if (index == 2 * n) {
	        res.add(str.toString());
	        return;
	    }
	    
	    str.append('(');
	    rec(leftCount + 1, rightCount, index + 1, str, n);
	    str.deleteCharAt(str.length() - 1);
	    
	    str.append(')');
	    rec(leftCount, rightCount + 1, index + 1, str, n);
	    str.deleteCharAt(str.length() - 1);
	    
	}
	
	
}
----------------------------------
class Solution:
    def generateParenthesis(self, A):
        self.output = set()
        self.generate(A, ['('])
        return sorted(self.output)

    def generate(self, n, braces):
        if len(braces) == 2*n:
            self.output.add(''.join(braces))
            return

        if braces.count('(') < n:
            self.generate(n, braces + ['('])

        if braces.count(')') < braces.count('('):
            self.generate(n, braces + [')'])

*/
