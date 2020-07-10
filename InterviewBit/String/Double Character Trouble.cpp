/*
Double Character Trouble
Problem Description

You are given a string A.

An operation on the string is defined as follows:

Remove the first occurrence of same consecutive characters. eg for a string "abbcd", the first occurrence of same consecutive characters is "bb".

Therefore the string after this operation will be "acd".

Keep performing this operation on the string until there are no more occurrences of same consecutive characters and return the final string.



Problem Constraints
1 <= |A| <= 100000



Input Format
First and only argument is string A.



Output Format
Return the final string.



Example Input
Input 1:

 A = abccbc
Input 2:

 A = ab


Example Output
Output 1:

 "ac"
Output 2:

 "ab"


Example Explanation
Explanation 1:

Remove the first occurrence of same consecutive characters. eg for a string "abbc", 
the first occurrence of same consecutive characters is "bb".
Therefore the string after this operation will be "ac".
Explanation 2:

 No removals are to be done.
 
 
*/

typedef int ll;
string Solution::solve(string A) {
    
        string s=A;
		stack<char> st;
		//we maintain a stack for the characters of the string
		st.push('#');
		st.push(s[0]);
		for(ll i=1;i<s.length();i++)
		{
		    //if the current character is equal to the top of the stack
		    //then they form a pair of consecutive similar characters
		    //therefore we pop from the stack
		    //else we push the charcter in the stack
			if(s[i]==st.top())
				st.pop();
			else 
				st.push(s[i]);
		}
		vector<char> ans;
		//we store the contents of the stack in a vector of characters.
		while(st.top()!='#')
		{
			ans.push_back(st.top());
			st.pop();
		}
		//since the final string is in reverse order, we reverse it and return the string
		reverse(ans.begin(),ans.end());
		string final="";
		for(ll i=0;i<ans.size();i++)
			final+=ans[i];
			
		return final;	

		
}

/*

#define dbg printf("in\n")
#define nl printf("\n")
#define N 20
#define inf 1e9

#define pb push_back
#define pp pair<int, int>
string Solution::solve(string S) 
{
     string ret = "";
     int n = S.length();
     stack<char> ss;
     for(int i = 0; i < n; i++)
    {
        if(ss.empty()) ss.push(S[i]);
        else
        {
            if(ss.top() == S[i])
                ss.pop();
            else
                ss.push(S[i]);
        }
    }      
        
        
    while(ss.size())
        ret.pb(ss.top()), ss.pop();    
        
    reverse(ret.begin(), ret.end());
        
    return ret;
}

*/