/*
https://leetcode.com/problems/subarray-sum-equals-k/
560. Subarray Sum Equals K

Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


*/

//sol->

/*
Explanation: we keep an accumulator variable sum with the running total of the sum of numbers; 
we then check if we have already met that values using our seen hashmap that acts more or less like a frequency table, 
storing how many times we have encountered a specific value: sum - k.

That is why if have met sum - k before and now the value is sum, the difference between those specific points and 
the current iteration is, by definiton, exactly k: we are now at sum, so, the interval between the previous point(s) 
and now sums up to, by definition, sum - (sum - k), which equates k.

We collect all those occurrences in count and finally we return it.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> seen = {{0, 1}};
        int count = 0, sum = 0;
        for (auto n: nums) 
        {
            sum += n;
            count += seen[sum - k];
            seen[sum]++;
        }
        return count;
    }
};
