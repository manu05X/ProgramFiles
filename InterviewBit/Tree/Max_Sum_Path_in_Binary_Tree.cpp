/*
Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

Input Format:

The first and the only argument contains a pointer to the root of T, A.
Output Format:

Return an integer representing the maximum sum path.
Constraints:

1 <= Number of Nodes <= 7e4
-1000 <= Value of Node in T <= 1000
Example :

Input 1:

       1
      / \
     2   3

Output 1:
     6

Explanation 1:
    The path with maximum sum is: 2 -> 1 -> 3

Input 2:
    
       -10
       /  \
     -20  -30

Output 2:
    -10

Explanation 2
    The path with maximum sum is: -10
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
 
 int findMax(TreeNode* root,int &result)
 {
     //Base Case 
    if(root == NULL)
        return 0;
    // l and r store maximum path sum going through left and 
    // right child of root respectively 
     int l = findMax(root->left, result);
     int r = findMax(root->right, result);
     
      // Max path for parent call of root. This path must 
      // include at-most one child of root
     int max_single = max(max(l,r) + root->val, root->val);
     
     // Max Top represents the sum when the Node under 
    // consideration is the root of the maxsum path and no 
    // ancestors of root are there in max sum path 
     int max_top = max(max_single, l+r+root->val);
     
     result=max(result,max_top);
     
     return max_single;
 }
 
int Solution::maxPathSum(TreeNode* A) {
    int result = INT_MIN;
    findMax(A,result);
    
    return result;
}
