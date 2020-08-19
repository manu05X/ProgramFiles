46. Permutations :- https://leetcode.com/problems/permutations/

class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        vector<int> res;
        unordered_map<int,bool> ump;
        solve(nums, res, ump);
        return ans;
    }
private:
    void solve(vector<int>& nums, vector<int> res, unordered_map<int,bool> ump)
    {
        if (res.size() == nums.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if (ump[nums[i]] == true)
                continue;
            res.push_back(nums[i]);
            ump[nums[i]] = true;
            solve(nums, res, ump);
            res.pop_back();
            ump[nums[i]] = false;
        }
    }
};

47. Permutations II :- https://leetcode.com/problems/permutations-ii/

class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        vector<int> res;
        unordered_map<int,bool> ump;
        sort(begin(nums),end(nums));
        solve(nums, res, ump);
        return ans;
    }
private:
    void solve(vector<int>& nums, vector<int> res, unordered_map<int,bool> ump)
    {
        if (res.size() == nums.size())
        {
            ans.push_back(res);
            return;
        }
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if (ump[i] == true || i > 0 && nums[i] == nums[i-1] && ump[i-1] == false)
                continue;
            res.push_back(nums[i]);
            ump[i] = true;
            solve(nums, res, ump);
            res.pop_back();
            ump[i] = false;
        }
    }    
};

31. Next Permutation :- https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return;
        if (n == 2)
        {
            swap(nums[0],nums[1]);
            return;
        }
        int j = n-1;
        while(j > 0)
        {
            if (nums[j-1] < nums[j])
            {
                reverse(begin(nums)+j,end(nums));
                auto idx = upper_bound(begin(nums)+j,end(nums),nums[j-1]) - begin(nums);
                swap(nums[j-1],nums[idx]);
                return;
            }
            j--;
        }
        sort(begin(nums),end(nums));
        return;
    }
};

60. Permutation Sequence :- https://leetcode.com/problems/permutation-sequence/

class Solution {
    vector<int> fact;
    vector<string> digits;
    string ans;
public:
    string getPermutation(int n, int k) {
        fact = vector<int>(n);
        digits = vector<string>(n);
        ans = "";
        fact[0] = 1;
        for(int i = 1 ; i < n ; i++)
            fact[i] = fact[i-1] * i;
        for(int i = 1 ; i <= n ; i++)
            digits[i-1] = to_string(i);
        solve(n,k);
        return ans;
    }
private:
    void solve(int n, int k)
    {
        if (n == 1)
        {
            ans += digits[0];
            return;
        }
        int index = k/fact[n-1];
        if (k % fact[n-1] == 0)
            index--;
        ans = ans + digits[index];
        digits.erase(begin(digits)+index);
        k = k - fact[n-1] * index;
        n--;
        solve(n,k);
    }
};

78. Subsets :- https://leetcode.com/problems/subsets/

class Solution {
    int len, n;
    vector<vector<int> > ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        n = (int)nums.size();
        vector<int> res;
        for(len = 0 ; len <= n ; len++)
            solve(nums, 0, res);
        return ans;
    }
private:
    void solve(vector<int>& nums, int index, vector<int> res)
    {
        if ((int)res.size() == len)
            ans.push_back(res);
        for(int i = index ; i < n ; i++)
        {
            res.push_back(nums[i]);
            solve(nums, i + 1, res);
            res.pop_back();
        }
    }
};

90. Subsets II :- https://leetcode.com/problems/subsets-ii/

class Solution {
    int len, n;
    vector<vector<int> > ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        n = (int)nums.size();
        vector<int> res;
        sort(begin(nums),end(nums));
        // for(len = 0 ; len <= n ; len++)
        solve(nums, 0, res);
        return ans;
    }
private:
    void solve(vector<int>& nums, int index, vector<int>& res)
    {
        ans.push_back(res);
        for(int i = index ; i < n ; i++)
        {
            if (i > index && nums[i] == nums[i-1])
                continue;
            res.push_back(nums[i]);
            solve(nums, i + 1, res);
            res.pop_back();
        }
    }
};

77. Combinations :- https://leetcode.com/problems/combinations/

class Solution {
    vector<vector<int> > ans;
public:
    void solve(int& n, int k, int curN, vector<int>& cur)
    {
        if (k == 0)
        {
            ans.push_back(cur);
            return;
        }
        if (curN > n)
            return;
        for(int idx = curN ; idx <= n ; idx++)
        {
            cur.push_back(idx);
            solve(n, k-1, idx+1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> cur;
        solve(n, k, 1, cur);
        return ans;
    }
};

39. Combination Sum :- https://leetcode.com/problems/combination-sum/

class Solution {
    set<vector<int>> ans;
public:
    void solve(vector<int>& candidates, int& target, int idx, int curSum, vector<int> cur)
    {
        if (curSum == target)
        {
            ans.insert(cur);
            return;
        }
        if (curSum > target)
            return;
        if (idx >= candidates.size())
            return;
        for(int i = idx ; i < candidates.size() ; i++)
        {
            curSum += candidates[i];
            cur.push_back(candidates[i]);
            solve(candidates, target, i, curSum, cur);
            curSum -= candidates[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> cur;
        sort(begin(candidates), end(candidates));
        solve(candidates, target, 0, 0, cur);
        vector<vector<int>> res;
        for(auto it : ans)
            res.push_back(it);
        return res;
    }
};

17. Letter Combinations of a Phone Number :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string &digits, string cur, int idx, vector<string> &ans)
    {
        if (idx == digits.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int i = 0 ; i < keypad[digits[idx]-'0'].size() ; i++)
        {
            cur.push_back(keypad[digits[idx]-'0'][i]);
            solve(digits, cur, idx+1, ans);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() < 1)
            return ans;
        solve(digits, "", 0, ans);
        return ans;
    }
};

40. Combination Sum II :- https://leetcode.com/problems/combination-sum-ii/

class Solution {
    set<vector<int>> ans;
public:
    void solve(vector<int>& candidates, int& target, int idx, int curSum, vector<int> cur)
    {
        if (curSum == target)
        {
            ans.insert(cur);
            return;
        }
        if (curSum > target)
            return;
        if (idx >= candidates.size())
            return;
        for(int i = idx ; i < candidates.size() ; i++)
        {
            curSum += candidates[i];
            cur.push_back(candidates[i]);
            solve(candidates, target, i+1, curSum, cur);
            curSum -= candidates[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> cur;
        sort(begin(candidates), end(candidates));
        solve(candidates, target, 0, 0, cur);
        vector<vector<int>> res;
        for(auto it : ans)
            res.push_back(it);
        return res;
    }
};

216. Combination Sum III :- https://leetcode.com/problems/combination-sum-iii/

class Solution {
    vector<vector<int> > ans;
    int K, N;
public:
    void solve(int n, int curSum, vector<int>& cur)
    {
        if (curSum == N and cur.size() == K)
        {
            ans.push_back(cur);
            return;
        }
        if (curSum > N)
            return;
        if (cur.size() > K)
            return;
        for(int num = n ; num < 10 ; num++)
        {
            cur.push_back(num);
            solve(num+1, curSum + num, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> cur;
        K = k;
        N = n;
        solve(1, 0, cur);
        return ans;
    }
};

377. Combination Sum IV :- https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] = ((long int)dp[i]+dp[i-num])%2147483647 ;
            }
        }
        return dp.back();
    }
};

22. Generate Parentheses :- https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    void generate(string cur,int open,int close,int n,vector<string> &ans){
        if(cur.length()>=2*n){
            if(open==close && open==n){
                ans.push_back(cur);
                return;
            }else{
                return;
            }
        }
        if(open==n && close<open){
            cur.push_back(')');
            generate(cur,open,close+1,n,ans);  
        }
        if(open == close && open < n){
            cur.push_back('(');
            generate(cur,open+1,close,n,ans);
        }
        if(open>close){
            if(open<n){
                cur.push_back('(');
                generate(cur,open+1,close,n,ans);
            }
            {
                cur.push_back(')');
                generate(cur,open,close+1,n,ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("",0,0,n,ans);
        return ans;
    }
};

20. Valid Parentheses :- https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                char tp = st.top();
                st.pop();
                char cur = s[i];
                if(cur==')' && (tp=='{' || tp=='['))
                    return false;
                if(cur=='}' && (tp=='(' || tp=='['))
                    return false;
                if(cur==']' && (tp=='{' || tp=='('))
                    return false;
            }
        }
        return st.empty();
    }
};