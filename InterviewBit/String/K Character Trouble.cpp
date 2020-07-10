/*
K Character Trouble
Problem Description

Given a string A. An operation on the string is defined as follows:

Remove the first occurrence of same consecutive B characters.

Keep performing this operation on the string until there are no more occurrences of same B consecutive characters and return the final string.



Problem Constraints
1 <= length(A) <= 100000

1 <= B <= |A|

All the alphabets of A are lowercase (a - z).



Input Format
The first argument given is a String A.

The second argument given is an integer B.



Output Format
Return the final string.



Example Input
Input 1:

 A = "abbbc"
 B = 3
Input 2:

 A = "abbac"
 B = 2


Example Output
Output 1:

 "ac"
Output 2:

 "c"


Example Explanation
Explanation 1:

 In the first iteration we will remove the 3 consecutive 'b's to get "ac".
Explanation 2:

 In the first iteration we will remove the 2 consecutive 'b's to get "aac".
 In the second iteration we will remove the 2 consecutive 'a's to get "c".
 
 
*/

string Solution::solve(string s, int k) 
{
    string ans = "";
      stack < pair<char, int> > st;
      int n = s.size();
      for(int i = 0; i <= n;)
      {
         char x = s[i];
         if(!st.empty() && st.top().second == k)st.pop();
         if(i == n)break;
         if(st.empty() || st.top().first != x)
         {
            st.push({x, 1});
            i++;
         } else 
         {
            st.top().second++;
            i++;
         }
      }
      while(!st.empty())
      {
         pair <char, int> temp = st.top();
         while(temp.second--) ans += temp.first;
         st.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans;
}


/*

typedef int ll;
string Solution::solve(string A, int B) {
    
        ll k;
		string s;
		s=A;k=B;
		stack<pair<char,ll> > st;
		//stack of pair of character and integer to store the count of occuring characters
		for(ll i=0;s[i]!='\0';i++)
		{
			if(st.empty())
			{   
			    //if stack is empty, push the character with count=1
				st.push(make_pair(s[i],1));
			}
			else
			{
			    //if stack is not empty, take the top of the stack in variable temp
				pair<char,ll> temp=st.top();
				//if top of the stack if equal to the current character
				//check if the count of the top is equal to k-1
				//if yes, it implies that K-1 characters of same alphabet have already occurred therefore
				//pop k-1 characters from stack
				if(s[i]==temp.first)
				{
					if(temp.second==(k-1))
					{
						while(true)
						{
							if(st.empty()==1)
								break;

							if(st.top().first==s[i])
								st.pop();
							else
								break;
						}
					}
					else
					{
					    //else push the character with count 1 greater than the top of the stack
						st.push(make_pair(s[i],temp.second+1));
					}
				}
				else
				{
					st.push(make_pair(s[i],1));
				}
			}
		}
		
		string ans="";
		//ans will store the final answer which will be the reverse of the contents of the stack
		while(st.empty()!=1)
		{
			ans+=st.top().first;
			st.pop();
		}
		reverse(ans.begin(),ans.end());
        
        //if k==1, all characters will be removed so the answer will be an empty string
		if(k==1)
			ans="";
		
		return ans;
}

*/