/*
https://leetcode.com/problems/split-array-largest-sum/

410. Split Array Largest Sum
*/


/*
The problem can be solved by using binary search, which is a quite brilliant way. If m equals length of the array, the largest sum should be the maximum among the elements. If m equals 1, then it should be the sum of all elements in the array. Now the maximum sum of a subarray should be between these two numbers.

The idea is to using binary search and find this minimum maximum sum. We set left to the maximum element of the array and right to the sum of the array. First we choose the mid of these two and find if there exist m subarrays that have largest sum less than or equal to mid. If we can find such split, we know we probably can do better. So we set right to mid. We keep on doing this until we find a value that we cannot get by splitting the array to m subarrays, i.e., the number is too small that we need to split the array further more. Now we increase left to mid + 1. When left = right, we find the number.


[7, 2, 5, 10, 8] m = 2

left = 10, right = 32, mid = 21 => [7, 2, 5], [10, 8]

left = 10, right = 21, mid = 15 => [7, 2], [10, 5],[8]

left = 16, right = 21, mid = 18 => [7, 2], [10, 8]

left = 16, right = 18, mid = 17 => [7, 2], [10, 5],[8]

left = 18, right = 18 => return 18


(Just a guess), the minimum maximum sum should be the mid number when one of the subarrays has the sum equal to it.
*/

class Solution {
public:
    bool canSplit(vector<int>& nums, int maxVal, int m) 
    {
        int countSub = 1;
        int currSum = 0;
        for (int n : nums)
        {
            currSum += n;
            if (currSum > maxVal) 
            {
                currSum = n;
                countSub++;
                if (countSub > m) 
                {
                    return false;
                }
            }
        }
        return true;
    }
      
    int splitArray(vector<int>& nums, int m) 
    {
        if (nums.size() == 0) 
        {
            return 0;
        }
        int left = 0, right = 0;
        for (int n : nums) {
            left = max(left, n);
            right += n;
        }
        if (m == nums.size()) 
        {
            return left;
        }
        if (m == 1) 
        {
            return right;
        }
        while (left < right) 
        {
            int mid = (left + right) / 2;
            if (canSplit(nums, mid, m)) 
            {
                right = mid;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        return left;
    }
};