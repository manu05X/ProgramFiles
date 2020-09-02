/*
https://leetcode.com/problems/non-overlapping-intervals/
*/

//sol->

class Solution {
public:
     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());    //Sort all intervals in ASC order
        int count = 0;      //Count of number of intervals to be removed
        int n = intervals.size();   //No of intervals
        int left = 0;   //left interval ptr
        int right = 1;  //right interval ptr
        
        while(right<n)  //Unless all intervals are compared
        {
            if(intervals[left][1] <= intervals[right][0])   //Non-overlapping case
            {
                left = right;
                right+=1;
            }
            else if(intervals[left][1]<=intervals[right][1])    //Overlapping case-1 (Remove right interval)
            {
                count+=1;       //Delete right
                right+=1;
            }
            else if(intervals[left][1]>intervals[right][1])     //Overlapping case-2 (Remove left interval)
            {
                count+=1;
                left = right;
                right+=1;
            }
        }
        
        return count;
    }
};

/*
nlog(n)


bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) 
	{
		int ans=-1;      
		if(intervals.size()==0) 
			return 0;       
		
		sort(intervals.begin(),intervals.end(),comp);      //custom comperator is used.
		vector<int> prev= intervals[0];

		for(vector<int> i: intervals) 
		{
			if(prev[1]>i[0]) 
			{
				ans++;                //we dont update previous, because i[1] will be grater then prev[1]
			}
			else 
				prev=i;           // we want the end point to be minimum
		}
		return ans;                 //ans was initially made -1 because our prev and intervals[0] will always match
	}
};
*/