/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

3. Longest Substring Without Repeating Characters

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        vector<int>prev(128,-1); // current index of character
        // try to extend the range [i, j]
		int i = 0;
        for (int j = 0, j < n; j++) 
        {
            i = max(prev[s[j]]+1, i);
			int maxEnd = j-i+1;
            ans = max(ans, maxEnd);
            prev[s[j]] = j;
        }
        return ans;
    }
};


//method 2

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int left = 0, right =0;
        // characters between left and right will always be unique
        
        map<int, int> last_seen;
        // store the latest occrrence of a character, 
        // s[i] -> never seen before -> add to window
        // s[i] -> seen before -> could be added or could not be added
                
        while (right < s.length() and left < s.length())
        {
            
            
            if (last_seen.find(s[right]) == last_seen.end())  
            {
                // s[right] is appearing for the first time.
                last_seen[s[right]] = right;
            }
                
                
            else
            {
                // s[right] has previously appeared in the string.
                
                
                if (last_seen[s[right]] >= left)
                {
                    
                    // _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  (string)
                    //       ^       ^           ^
                    //       |       |           |   
                    //      left  last_seen   s[right]
                    //            [s[right]]
                    
                    left = last_seen[s[right]] + 1; // update window start and end
                    
                }
            }
                    
            result = max(result, right-left+1);
            last_seen[s[right]] = right;
            right += 1; // move to next char
                        
        }

        return result;
    }
};