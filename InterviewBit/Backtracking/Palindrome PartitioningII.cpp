//https://leetcode.com/problems/palindrome-partitioning-ii/
//132. Palindrome Partitioning


class Solution {
public:
    int minCut(string s) 
    {
        queue<int> node;
		node.push(0);
		int cuts = 0;
		//bfs
		vector<bool> visited(s.size(), false);
		while (true){
			queue<int> tmp;
			while (!node.empty()){
				int cur = node.front();
				node.pop();
				for (int i = s.size() - 1; i >= cur; i--)
                {
					if (visited[i]==false&&ispal(s, cur, i))
                    {
						if (i == s.size() - 1)
							return cuts;
						tmp.push(i+1);
					}
				}
				visited[cur] = true;
			}
			cuts++;
			node = tmp;
		}
	}

	bool ispal(string& s, int pre, int post){
		while (pre < post)
        {
			if (s[pre++] != s[post--])
				return false;
		}
		return true;
    }
};

/*
Took me a while to understand. I'd like to help further explain it.

The definition of 'cut' array is the minimum number of cuts of a sub string. 
More specifically, cut[n] stores the cut number of string s[0, n-1].

Here is the basic idea of the solution:

Initialize the 'cut' array: For a string with n characters s[0, n-1], it needs at most n-1 cut. 
Therefore, the 'cut' array is initialized as cut[i] = i-1

Use two variables in two loops to represent a palindrome:
The external loop variable 'i' represents the center of the palindrome. The internal loop variable 'j' 
represents the 'radius' of the palindrome. Apparently, j <= i is a must.
This palindrome can then be represented as s[i-j, i+j]. If this string is indeed a palindrome, 
then one possible value of cut[i+j] is cut[i-j] + 1, where cut[i-j] corresponds to s[0, i-j-1] 
and 1 correspond to the palindrome s[i-j, i+j];

When the loops finish, you'll get the answer at cut[s.length]


It uses only O(n) space.

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) 
			cut[i] = i-1;
        for (int i = 0; i < n; i++) 
		{
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
*/