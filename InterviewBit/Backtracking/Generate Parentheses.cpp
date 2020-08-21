//https://leetcode.com/problems/generate-parentheses/
22. Generate Parentheses


class Solution {
public:
     vector < string > ans;
    
    void rec(const int &n, int open, int close, string s)
    {
        
        if (s.size() == 2*n)
        {
            ans.push_back(s);
            return;
        }
        
        if (open < n)
            rec(n, open + 1, close, s + '(');

        if (open > close)
            rec(n, open, close + 1, s + ')');
    }
    
    vector<string> generateParenthesis(int n) 
    {
        rec(n, 0, 0, "");
        return ans;
    }
};