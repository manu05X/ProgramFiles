/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
 3. Longest Substring Without Repeating Characters
 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), len = 0;
        vector<int>prev(128,-1); // current index of character
        // try to extend the range [left, right]
		int left = 0,right = 0;
        while(right < n) 
        {
            // if char at right is in map then increase the left to curr right + 1 provided it is not present in left of left
            if(prev[s[right]] != -1)
                left = max(prev[s[right]]+1, left);
            
            //update the current index in hashmap
            prev[s[right]] = right;
            
			int currLen = right-left+1; // length of current subString
            len = max(len, currLen); // if currLen id greater then len then upadte it
            
            right++;
            
        }
        return len;
    }
};




/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(),res = 0;
        for(int i = 0; i < n; i++)
        {
            vector<bool>visited(256);
            for(int j = i ; j < n; j++)
            {
                if(visited[s[j]] == true)
                    break;
                else
                {
                    res = max(res, j-i+1);
                    visited[s[j]] = true;
                }
            }
        }
        return res;
    }
};


public class Solution {
  public int lengthOfLongestSubstring(String s) {
    int max = 0;
    Map<Character, Integer> map = new HashMap<>();
    // range is [start, i]
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
      if (map.containsKey(s.charAt(i))) {
        start = Math.max(map.get(s.charAt(i)) + 1, start);
      }
      max = Math.max(max, i - start + 1);
      map.put(s.charAt(i), i);
    }
    return max;
  }
}

*/