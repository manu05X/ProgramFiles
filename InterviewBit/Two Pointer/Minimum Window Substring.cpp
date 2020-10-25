/*
https://leetcode.com/problems/minimum-window-substring/

76. Minimum Window Substring

*/

/*
There are three key variables in my solution:

unordered_map <char, int> map; unordered_map<char, int> window; int letterCounter;
variable "map" is used to indicate what characters and how many characters are in T.

variable "window" is to indicate what characters and how many characters are between pointer "slow" and pointer "fast".

Now let's start.

The first For loop is used to construct variable "map".

The second For loop is used to find the minimum window.

The first thing we should do in the second For loop is to find a window which can cover T. I use "letterCounter" to be a monitor. 
If "letterCounter" is equal to T.length(), then we find this window. Before that, only the first If clause can be executed. 
However, after we find this window, the second If clause can also be executed.

In the second If clause, we move "slow" forward in order to shrink the window size. Every time finding a smaller window, 
I update the result.

At the end of program, I return result, which is the minimum window.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        string result;
        if(S.empty() || T.empty())
        {
            return result;
        }
        unordered_map<char, int> map;
        unordered_map<char, int> window;
        for(int i = 0; i < T.length(); i++)
        {
            map[T[i]]++;
        }
        int minLength = INT_MAX;
        int letterCounter = 0;
        for(int slow = 0, fast = 0; fast < S.length(); fast++)
        {
            char c = S[fast];
            if(map.find(c) != map.end())
            {
                window[c]++;
                if(window[c] <= map[c])
                {
                    letterCounter++;
                }
            }
            if(letterCounter >= T.length())
            {
                while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]])
                {
                    window[S[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < minLength)
                {
                    minLength = fast - slow + 1;
                    result = S.substr(slow, minLength);
                }
                // shrink the window here
                window[S[slow]]--;
                slow++;
                letterCounter--;
            }
        }
        return result;
    }
};


// mathod 2

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> letters; //unordered map for storing the characters in t that we need to check for in s
        for(auto c : t) 
            letters[c]++; 
        int count = 0; //counts number of t's letters in current window
        int low = 0, min_length = INT_MAX, min_start = 0;     
        for(int high = 0; high<s.length(); high++) 
        {
            if(letters[s[high]] > 0) 
                count++; //means that this letter is in t   
            letters[s[high]]--; //reduce the count for the letter on which we are currently 
            if(count == t.length()) 
            { //if current windows contains all of the letters in t
                while(low < high && letters[s[low]] < 0)
                    letters[s[low]]++, low++; //move low ahead if its not of any significance
                if(min_length > high-low) 
                    min_length = high-(min_start=low)+1; //update the min length
                letters[s[low++]]++; //move low ahaead and also increment the value
                count--; //count-- as we are moving low ahead & low pointed to a char in t before
            }
        }
        return min_length == INT_MAX ? "" : s.substr(min_start, min_length); //check for edge case & return the result
    }
};