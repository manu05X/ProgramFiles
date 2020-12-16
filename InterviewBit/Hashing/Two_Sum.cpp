/*
https://leetcode.com/problems/two-sum/
1. Two Sum

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