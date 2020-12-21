// https://leetcode.com/problems/4sum/

// 4SUM


class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    
        vector<vector<int> > res;
    
        if (num.empty())
            return res;
    
        std::sort(num.begin(),num.end());
    
        for (int i = 0; i < num.size(); i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < num.size(); j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = num.size() - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3 i.e quadruplet[2]
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4 i.e quadruplet[3]
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                // Processing the duplicates of number 1 i.e j 
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1 i.e j 
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    
    }
};

/*

Approach 2: Hash Set
Since elements must sum up to the exact target value, we can also use the Two Sum: One-pass Hash Table approach.

In 3Sum: Hash Set, we solved the problem without sorting the array. To do that, we needed to sort values within triplets, 
and track them in a hash set. Doing the same for k values could be impractical.

So, for this approach, we will also sort the array and skip duplicates the same way as in the Two Pointers approach above. 
Thus, the code will only differ in the twoSum implementation.

Algorithm

twoSum implementation here is almost the same as in Two Sum: One-pass Hash Table. 
The only difference is the check to avoid duplicates. Since the array is sorted, we can just compare 
the found pair with the last one in the result res.

*/

/*

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 4);
}
vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}
vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    unordered_set<int> s;
    for (auto i = start; i < nums.size(); ++i) {
        if (res.empty() || res.back()[1] != nums[i])
            if (s.count(target - nums[i]))
                res.push_back({ target - nums[i], nums[i]});
        s.insert(nums[i]);
    }
    return res;
}

*/