/*
Given a binary tree of integers. Return an array of integers representing the left view of the Binary tree.

Left view of a Binary Tree is a set of nodes visible when the tree is visited from Left side

Constraints

1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 
For Example

Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Output 1:
    [1, 2, 4, 8]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
Output 2:
    [1, 2, 4, 5]
*/








/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> leftview(TreeNode* A,int level,int *max_level,vector<int> &ans)
 {
    if(A ==NULL)
        return ans;
        
    if(*max_level<level)
    {
        ans.push_back(A->val);
        *max_level=level;
        
    }
    leftview(A->left,level+1,max_level,ans);
    leftview(A->right,level+1,max_level,ans);
    
    return ans;
 }
 
vector<int> Solution::solve(TreeNode* A)
{
     vector<int>ans;
     int max_level=0;
     return leftview(A,1,&max_level,ans);
    
}
    
int Solution::maxPathSum(TreeNode* A) {
    int result = INT_MIN;
    findMax(A,result);
    
    return result;
}
