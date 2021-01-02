/*
https://leetcode.com/problems/meeting-rooms-ii/

253. Meeting Rooms II
Medium

3217

53

Add to List

Share
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mp; // key: time; val: +1 if start, -1 if end

        for(int i=0; i< intervals.size(); i++) 
        {
            mp[intervals[i][0]] ++;
            mp[intervals[i][1]] --;
        }
		/*
			intervals: {{0, 30}, {5, 10}, {15, 20}}
			mp: {[0] = 1, [5] = 1, [10] = -1, [15] = 1, [20] = -1, [30] = -1}
		*/
        int cnt = 0, maxCnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) 
        {
            cnt += it->second;
            maxCnt = max( cnt, maxCnt);
        }

        return maxCnt;
    }
};