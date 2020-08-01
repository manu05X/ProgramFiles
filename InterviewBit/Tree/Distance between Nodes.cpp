/*
Distance between Nodes of BST
Problem Description

Given a binary search tree.
Return the distance between two nodes with given two keys B and C. It may be assumed that both keys exist in BST.

NOTE: Distance between two nodes is number of edges between them.



Problem Constraints
1 <= Number of nodes in binary tree <= 1000000

0 <= node values <= 109



Input Format
First argument is a root node of the binary tree, A.

Second argument is an integer B.

Third argument is an integer C.



Output Format
Return an integer denoting the distance between two nodes with given two keys B and C



Example Input
Input 1:

    
         5
       /   \
      2     8
     / \   / \
    1   4 6   11
 B = 2
 C = 11
Input 2:

    
         6
       /   \
      2     9
     / \   / \
    1   4 7   10
 B = 2
 C = 6


Example Output
Output 1:

 3
Output 2:

 1


Example Explanation
Explanation 1:

 Path between 2 and 11 is: 2 -> 5 -> 8 -> 11. Distance will be 3.
Explanation 2:

 Path between 2 and 6 is: 2 -> 6. Distance will be 1
 
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
 
// This function returns distance of x from 
// root. This function assumes that x exists 
// in BST and BST is not NULL. 
int distanceFromRoot(TreeNode* root, int x) 
{ 
    if (root->val == x) 
        return 0; 
    else if (root->val > x) 
        return 1 + distanceFromRoot(root->left, x); 
    return 1 + distanceFromRoot(root->right, x); 
} 
  
// Returns minimum distance between a and b. 
// This function assumes that a and b exist 
// in BST. 
int distanceBetween2(TreeNode* root, int a, int b) 
{ 
    if (!root) 
        return 0; 
  
    // Both keys lie in left 
    if (root->val > a && root->val > b) 
        return distanceBetween2(root->left, a, b); 
  
    // Both keys lie in right 
    if (root->val < a && root->val < b) // same path 
        return distanceBetween2(root->right, a, b); 
  
    // Lie in opposite directions (Root is 
    // LCA of two nodes) 
    if (root->val >= a && root->val <= b) 
        return distanceFromRoot(root, a) +  
               distanceFromRoot(root, b); 
} 
 
 
int Solution::solve(TreeNode* root, int a, int b) {
    if (a > b) 
     swap(a, b); 
   return distanceBetween2(root, a, b); 
}
