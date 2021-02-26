/*
https://leetcode.com/problems/two-sum/
1. Two Sum

*/

/*
Two-pass Hash Table

We reduce the look up time from O(n)O(n) to O(1)O(1) by trading space for speed. 
A hash table is built exactly for this purpose, it supports fast look up in near constant time. 
I say "near" because if a collision occurred, a look up could degenerate to O(n)O(n) time. 
But look up in hash table should be amortized O(1)O(1) time as long as the hash function was chosen carefully.

A simple implementation uses two iterations. In the first iteration, we add each element's value and 
its index to the table. Then, in the second iteration we check if each element's complement 
(target - nums[i]target−nums[i]) exists in the table. Beware that the complement must not be nums[i]nums[i] itself!


*/
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        std::unordered_map<int, int> mp;
        
        for(int i =0 ; i < nums.size(); i++)
            mp.insert({nums[i], i});
        
        
        for(int i =0 ; i < nums.size(); i++)
        {
            int diff = target - nums[i];
			
			// if iterator mp does not point to end means it has found the required element in hash table            
            if(mp.find(diff) != mp.end()) 
            {
				// to check if diff index does'nt point to current i
                if(mp[diff] != i)  
                {
                    ans.push_back(i);
                    ans.push_back(mp[diff]);
                    break;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        unordered_map<int, int> hash;
	    vector<int> result;
	    for (int i = 0; i < numbers.size(); i++) 
        {
		  int numberToFind = target - numbers[i];
			// if iterator in hash does not point to end means it has found the required element in hash table
            //if numberToFind is found in map, return them
		   if (hash.find(numberToFind) != hash.end())
           {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		   }

            //number was not found. Put it in the map.
		  hash[numbers[i]] = i;
	    }
	return result;
    }
};