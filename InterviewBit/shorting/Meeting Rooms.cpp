/*
252. Meeting Rooms

Share
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return true;
        
         // sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a,const vector<int>& b)              {
            return a[0] < b[0];
        });

        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i-1][1] > intervals[i][0])
                return false;
        }
        return true;
    }
};