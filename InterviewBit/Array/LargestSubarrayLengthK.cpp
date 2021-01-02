/*
//https://leetcode.com/problems/largest-subarray-length-k/

1708. Largest Subarray Length K

An array A is larger than some array B if for the first index i where A[i] != B[i], A[i] > B[i].

For example, consider 0-indexing:

[1,3,2,4] > [1,2,2,4], since at index 1, 3 > 2.
[1,4,4,4] < [2,1,1,1], since at index 0, 1 < 2.
A subarray is a contiguous subsequence of the array.

Given an integer array nums of distinct integers, return the largest subarray of nums of length k.

 

Example 1:

Input: nums = [1,4,5,2,3], k = 3
Output: [5,2,3]
Explanation: The subarrays of size 3 are: [1,4,5], [4,5,2], and [5,2,3].
Of these, [5,2,3] is the largest.
Example 2:

Input: nums = [1,4,5,2,3], k = 4
Output: [4,5,2,3]
Explanation: The subarrays of size 4 are: [1,4,5,2], and [4,5,2,3].
Of these, [4,5,2,3] is the largest.
Example 3:

Input: nums = [1,4,5,2,3], k = 1
Output: [5]
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 109

*/

//sol->

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int max = -1;
        int max_index = -1;
        int n = nums.size();
        for (int i = 0; i + k <= n; i++) {
            if (nums[i] > max) {
                max_index = i;
                max = nums[i];
            }
        }
        
        vector<int> ans(nums.begin() + max_index, nums.begin() + max_index + k);
        return ans;
        
    }
};
/*
Idea:

all numbers are different
we can find the maximum number for nums[i] with i=0~n-k-1 as start index (then the resulting subarray will be the largest)
vector<int> largestSubarray(vector<int>& nums, int k) 
{
	int n=nums.size(),index=-1,maximum=0;
	for(int i=0;i<n-k+1;i++)
		if(nums[i]>maximum)
			maximum=nums[i],index=i;

	return vector<int>(nums.begin()+index,nums.begin()+index+k);
*/