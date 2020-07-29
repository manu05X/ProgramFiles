/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
 3. Longest Substring Without Repeating Characters
 
*/

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

/*

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