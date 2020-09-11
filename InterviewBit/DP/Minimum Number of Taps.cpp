/*
https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/submissions/

1326. Minimum Number of Taps to Open to Water a Garden

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.
*/

/*
Solution 1: Brute Force DP
dp[i] is the minimum number of taps to water [0, i].
Initialize dp[i] with max = n + 2
dp[0] = [0] as we need no tap to water nothing.

Find the leftmost point of garden to water with tap i.
Find the rightmost point of garden to water with tap i.
We can water [left, right] with onr tap,
and water [0, left - 1] with dp[left - 1] taps.
*/


//M-1
class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        
        // dp[i] is the min number of tapes to water area from 0 to i
        vector<int> dp(n+1,n+2); // Initialize with max 
        dp[0] = 0;               // minimum tapes needed to water area 0 is 0(basically no area)
        for(int i=0;i<=n;i++)  
        {
            int left = max(0,i-r[i]);     // find the minimum point of garden(area) to water with tape i.
            int right = min(n,i+r[i]);       // find the maximum point of garden(area) to water with tape i.
            for(int j=left+1;j<=right;j++)   
            {                
                //Check if this range from(left..right) can be watered using less number of tapes than previous
                dp[j] = min(dp[j], dp[left]+1); 
            }
        }
        
        // If mimimum tapes needed to water area 0..n is greater than n , it means we could not found minimum number of tapes
        if(dp[n]>=n+2)   
            return -1;
        return dp[n];
    }
};

________________________________________________________________________________________________________________
//M-2
class Solution 
{
	public:
    int minTaps(int n, vector<int>& ranges) 
	{
        int min = 0;
        int max = 0;
        int open = 0;
        int index = 0;
        while(max<n)
        { //10
            for(int i=index;i<ranges.size();i++)
            {      
              if(i-ranges[i]<=min && i+ranges[i]>max)
              {
                  max = i+ranges[i];  
                  index = i;
              }
          }
          if(min==max)
              return -1;
          open++;
          min = max;    
      }  
     return open;
    }
};