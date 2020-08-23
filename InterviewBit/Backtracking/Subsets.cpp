//https://leetcode.com/problems/subsets-ii/
// 90. Subsets II


example: given [2,1,2]

1. sort the given vector and get [1,2,2]

2. sss=[[]], with section=1, ending=1, j=0

3. copy [] and add '1', get

sss=[[],[1]], with section=2, ending=2, j=0

4. copy [],[1,2] and add '2's, get
sss=[[],[1],[2],[1,2]], with section=2, ending=4, j=2

5. copy [2],[1,2] and add '2's, get
sss=[[],[1],[2],[1,2],[2,2],[1,2,2]], break the while loop with section=2, ending=6, j=4

_

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> sss={v};
        
        int section=1; int ending=1;
        int i=0, j=0;
        
        sort(nums.begin(),nums.end());
        while (1) {
            for (;j<ending;j++) {
                sss.push_back(sss[j]);
                sss.back().push_back(nums[i]);
            }//copy the section and add the current number
            if ((++i)==nums.size()) break;
            else {
                ending+=section;
                if (nums[i]!=nums[i-1]) {section=ending; j=0;}
            }
        }
        return sss;
    }
};



/*
First use the hashmap to count the number of occurences of each distinct number and than use that hashmap to create the power set. The idea is similar to one where we don't have duplicates.
Ex. How to create power set of numbers [1,2,3]?
We will do that recursively. First, how to create the power set of [1].
The power set is {{}, {1}}.
Then, if we add another digit 2, the power set of [1,2] is created by adding the digit 2 to all previously created sets. That looks somehow like this:
{{}, {1}} U {{2}, {1,2}} = {{}, {1}, {2}, {1,2}}.
The case with dups is analog, where we process each distinct digit in one step:
[1, 2, 2] = {{}, {1}} U {{2}, {2, 2}, {1,2} , {1, 2, 2}}

class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::unordered_map<int, int> my_map;
        for (int x : nums)
        {
            my_map[x]++;
        }
        std::vector<std::vector<int>> result;
        result.push_back({});
        for (const auto &p : my_map)
        {
            int k = result.size();
            for (int i = 0; i < k; i++)
            {
                auto vec = result[i];
                for (int j = 0; j < p.second; j++)
                {
                    vec.push_back(p.first);
                    result.push_back(vec);
                }
            }
        }
        return result;
    }
};

_________________________________________________________________________


There are many good posts explaining the backtrack idea of these two topics.

The subset and permutation problems all have similar code. However, I did not find one that explains the difference between them. And despite the fact that they have similar code, actually they are very different.

subset I, II
My codes are similar to many others: push one element into the vector and then recursively call the function. After that pop that element out.
Explanation: The subset problem is all about choice, whether you want certain element inside the vector or not. For example, [1, 2, 3], starting with pos = 0. At pos = 0, you push 1 into temp, then recursively call the function. Then this reclusive call is a "crossroad". Inside the call (with all other calls inside), you have the "1" chosen and every vector you produce will begin with 1. When the call returns (ie. you pop 1 out), you are on the other road of the crossroad, which does not contain 1. These are just the first "choice" you are faced. And after that you face with other similar choices.
class Solution {
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int pos){
        res.push_back(temp);

        for(int i=pos; i<nums.size(); ++i){
            temp.push_back(nums[i]);
            helper(res, temp, nums, i + 1);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, nums, 0);
        return res;
    }
};
subset II : Eliminate the dup with sort and then the condition: do not put this element inside, if it has same element before && the former dup has not been put into it. Because otherwise, you better off put the former dup into the vector instead of this (latter dup) one.

class Solution {
    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums, int pos){
        res.push_back(temp);
        
        for(int i=pos; i<nums.size(); ++i){
            if(i != pos && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            helper(res, temp, nums, i + 1);
            temp.pop_back();
            
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(res, temp, nums, 0);
        return res;
    }
};
Permutation I, II
Permutation I is a very typical problem.
Note: the pos here is different with the pos in subset. The pos in subset is more like choice in front of crossroad while the pos in permutation is the "digit" you are considering. In other words, you you consider the elements one by one: which one should be the first? which one should be the second? ...and so on. The pos is just the "first", "second"...

When you consider the nth element, you swap the nth with element from nth to the last one, so that every element after that will have a chance to stay in the nth position. You recursively call, after each case.

class Solution {
    void helper(vector<vector<int>>& res, vector<int>& nums, int pos){
        if(nums.size() == pos){
            res.push_back(nums);
            return ;
        }
        for(int i=pos; i < nums.size(); ++i){
            swap(nums[i], nums[pos]);
            helper(res, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res, nums, 0);
        return res;
    }
};
permutation II
I prefer to use the unordered_map to solve the dup problem. How does it solve the problem? because it treats all the dup as one element with several copies.

For example, [1, 1, 2], when you iterate, in the same "level", the 1 will only be put once. We only put the other 1 into the vector in the recursive call in next levels.

class Solution {
    void helper(unordered_map<int, int>& bar, vector<int>& temp, vector<vector<int>>& res, int n){
        if(temp.size() == n){
            res.push_back(temp);
            return ;
        }
        for(auto &i : bar){
            if(i.second <= 0) continue;
            i.second --;
            temp.push_back(i.first);
            helper(bar, temp, res, n);
            temp.pop_back();
            i.second ++;
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> bar;
        for(int i : nums){
            bar[i] ++;
        }
        vector<int> temp;
        helper(bar, temp, res, nums.size());
        return res;
    }
};



*/
