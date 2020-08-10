/*
https://leetcode.com/problems/word-break/
*/

class Solution 
{
	public:
	unordered_map<string,bool> dp;

	bool solve_top_down(string s,set<string> st)
	{
		if(s.length()==0)
			return true;
		
		if(dp.count(s))
			return dp[s];
		
		for(auto r:st){
			int x=(int)r.length();
			string a=s.substr(0,x);
			
			if(r==a && solve_top_down(s.substr(x),st))
				return dp[s]=true;
		}
		return dp[s]=false;
	}
	bool solve_bottom_up(string s,set<string> st)
	{
		vector<bool> cache((int)s.length()+1,false);
		
		cache[0]=true;
		
		for(int i=1;i<=s.length();i++){
		 
			for(int j=i-1;j>=0;j--)
			{
			   // string f=s.substr(0,j);
				string g=s.substr(j,i-j);
				if(cache[j] && st.count(g))
					cache[i]=true;
			}
		}
		return cache[(int)s.length()];
	}
	bool wordBreak(string s, vector<string>& wordDict) 
	{
		set<string> st;
		
		for(auto s:wordDict)
			st.insert(s);
		return solve_bottom_up(s,st);
	}
};