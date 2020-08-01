/*
GREEDY PICK
Given a binary tree of integers.

Return the maximum value you can pick from nodes of given binary tree without picking any pair of nodes which are directly linked i.e. if you picked some node you cannot pick its children nodes

As answer can be very large return answer %10^9 + 7

Constraints

1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 
For Example

Input 1:
            3
          /   \
         2    3
          \    \
           3    1

Output 1:
    7
Explaination 1:
    Only nodes represented by _ are picked 
            _
          /   \
         2    3
          \    \
           -    -


Input 2:
            3
           /  \
          4    5
         / \    \
        1   3    1
Output 2:
    9
Explaination 2:
            3
           /  \
          -    -
         / \    \
        1   3    1
 
*/

//sol->

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ll long long
#define mod 1000000007 
vector<int> robSub(TreeNode* root) {
    if (root == NULL) {
        return vector<int>(2,0);
    }

    vector<int> left = robSub(root->left);
    vector<int> right = robSub(root->right);

    vector<ll> res(2,0LL);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];
    res[0]%=mod;
    res[1]%=mod;
    vector <int> ans(2);
    ans[0] = res[0];
    ans[1] = res[1];
    return ans;
}
int Solution::solve(TreeNode* A) {
    vector<int> res = robSub(A);
    return max(res[0], res[1]);
}
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*

//  Declaration of methods 
int sumOfGrandChildren(TreeNode* node); 
int getMaxSum(TreeNode* node); 
int getMaxSumUtil(TreeNode* node, map<struct TreeNode*, int>& mp); 

// method returns maximum sum possible from subtrees rooted 
// at grandChildrens of node 'node' 
int sumOfGrandChildren(TreeNode* node, map<struct TreeNode*, int>& mp) 
{ 
    int sum = 0; 
  
    //  call for children of left child only if it is not NULL 
    if (node->left) 
        sum += getMaxSumUtil(node->left->left, mp) + 
               getMaxSumUtil(node->left->right, mp); 
  
    //  call for children of right child only if it is not NULL 
    if (node->right) 
        sum += getMaxSumUtil(node->right->left, mp) + 
               getMaxSumUtil(node->right->right, mp); 
  
    return sum; 
} 
  
//  Utility method to return maximum sum rooted at node 'node' 
int getMaxSumUtil(TreeNode* node, map<struct TreeNode*, int>& mp) 
{ 
    if (node == NULL) 
        return 0; 
  
    // If node is already processed then return calculated 
    // value from map 
    if (mp.find(node) != mp.end()) 
        return mp[node]; 
  
    //  take current node value and call for all grand children 
    int incl = node->val + sumOfGrandChildren(node, mp); 
  
    //  don't take current node value and call for all children 
    int excl = getMaxSumUtil(node->left, mp) + 
               getMaxSumUtil(node->right, mp); 
  
    //  choose maximum from both above calls and store that in map 
    mp[node] = max(incl, excl); 
  
    return mp[node]; 
}
int Solution::solve(TreeNode* node) {
    if (node == NULL) 
        return 0; 
    map<struct TreeNode*, int> mp; 
    return getMaxSumUtil(node, mp); 
}
*/