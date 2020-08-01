/*
Build Identical Trees
Problem Description

Given two binary trees T1 and T2, you have to find minimum number of insertions to be done in T1 to make it structurally identical to T2.

Return -1 if not possible.

NOTE: You can insert any positive or negative integer.



Problem Constraints
1 <= Number of nodes <= 5 * 105


Input Format
First argument A denotes the root of tree T1.
Second argument B denotes the root of tree T2.



Output Format
Return an integer denoting the above described output.



Example Input
Input 1:

T1:       10
         /  \
        9    20

T2:       5
         / \
        2   7
       /
      1
Input 2:

T1:       10
         / \
        9   20

T2:       5
           \
            7


Example Output
Output 1:

 1
Output 2:

 -1


Example Explanation
Explanation 1:

 Insert a node into T1 as the left node of 9, it will be structurally identical to T2. Hence answer is 1.
Explanation 2:

 You cannot make T1 and T2 structurally identical. Hence answer is -1.

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

// Function to check, for every node in tree T1 there should node in tree T2 
bool check(TreeNode *A, TreeNode *B){
    if(A!= NULL && B == NULL){
        return 0;
    }
    
    if(A == NULL){
        return 1;
    }
    
    return check(A->left,B->left) && check(A->right, B->right);
}

// Count number of nodes in each tree

int countnode(TreeNode * root){
    if(root == NULL){
        return 0;
    }
    
    return 1 + countnode(root->left) + countnode(root->right);
}   

int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    if(check(A,B)){
        int cntT1 = countnode(A);
        int cntT2 = countnode(B);
        return cntT2 - cntT1;
    }
    else{
        return -1;
    }
}   

/*

 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 
 
public class Solution {
     public int cntMatrixUtil(TreeNode A, TreeNode B, int min,int max) {
        if(A!=null && B==null)
           return -1;
        int inserts=-1;
        if(A!=null && B!=null)inserts = 0;
        else inserts = 1;
        if(B==null && A==null)return 0;
        if(B !=null && A ==null)A = new TreeNode(min+(max-min)/2);
        int left = cntMatrixUtil(A.left, B.left, min, A.val);
        int right = cntMatrixUtil(A.right, B.right, A.val, max);
        if(left==-1 || right ==-1)return -1;
        return inserts + left + right;
    }
    public int cntMatrix(TreeNode A, TreeNode B) {
         return cntMatrixUtil(A,B,Integer.MIN_VALUE,Integer.MAX_VALUE);
    }
}

*/