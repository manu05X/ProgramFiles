/*
https://leetcode.com/problems/partition-labels/

763. Partition Labels

My core reasoning was:

	1> I need to find where is the last occurrence of the first character (initially setting start to 0);
	2> I then need to check all the characters between the first and the last, to update my rightmost index, and so on, until no new characters are between my first character and my rightmost limit;
	3> when no new characters are found, I store the size of my chunk, update start to parse the rest of the string and go on for possibly more loops.
Now, how I implemented it - first of all I declared a few variables:

	* start initialised to 0, as explained above, pos (our rightmost limit, len, initialised to s.size() and curr to store the value of the current character in a 0 - 25 range;
	* a boolean array seen of 26 slots to store which characters we encountered already (initially set to have them all to false) and the boolean switch hasNewSeen, the key of our loops;
	* our usual res variable to store our result.

As we start, we know we are going to loop until start < len, meaning we want to scan the whole string and will stop when we are done; we set hasNewSeen to true and assign curr a new value, matching the one of the char at s[start], normalised to be in the aforementioned 0 - 25 range and finally we update seen to take note of this character as already encountered.

Then we enter another loop that will run as long as hasNewSeen is true; inside:

	* we do a for loop without any action just to set the value of pos to be the index of the very last occurrence of the last seen character;
	* we reset hasNewSeen to false;
	* we loop inside the start + 1 - pos range (pos excluded) to check if we find new characters:
		* if so, we update seen and hasNewSeen;
		* if not, we will just exit the inner loop
	* we update res with the size of the latest range we found and we update start to be pos + 1.

Once also the outer loop is done running, we just return res :)
 
 
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // helper variables declared and initialised
        int start = 0, len = s.size(), pos, curr;
        vector<int> res;
        bool seen[26], hasNewSeen;
        for (int i = 0; i < 26; i++) seen[i] = false;
        while (start < len) {
            // setting up a new loop run
            hasNewSeen = true;
            curr = s[start] - 'a';
            seen[curr] = true;
            while (hasNewSeen) {
                // finding the last occurrence of the character at s[start]
                for (pos = len - 1; pos && !seen[s[pos] - 'a']; --pos);
                // resetting hasNewSeen
                hasNewSeen = false;
                // updating it with the characters in the new interval
                for (int i = start + 1; i < pos; i++) {
                    curr = s[i] - 'a';
                    if (!seen[curr]) {
                        seen[curr] = true;
                        hasNewSeen = true;
                    }
                }
            }
            // updating res and start
            res.push_back(pos - start + 1);
            start = pos + 1;
        }
        return res;
    }
};

// Method 2
/*
DRY RUN

S: "ababcbacadefegdehijhklij"
		 {a, b, c,  d,  e,  f,  g,  h,  i,  j,  k,  l}
end_idx: {8, 5, 7, 14, 15, 11, 13, 19, 22, 23, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
result: {9, 7, 8}
start: 24
end: 23
*/

class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        vector<int> end_idx(26, 0);
        for(int i = 0; i < S.length(); ++i)
        {
            end_idx[S[i] - 'a'] = i;
        }
        
        vector<int> result;
        int start = 0, end = 0;
        for(int i = 0; i < S.length(); ++i)
        {
            end = max(end, end_idx[S[i] - 'a']);
            if(i == end)
            { 
                // all the characters of current partition included
                result.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};