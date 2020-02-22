/*
Root to Leaf Paths With Sum:

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
 void putSum(TreeNode* root, vector<vector<int> >& sol, int sum, vector<int>& path){
   
    //checking whether sum is equal to 0, then push the path in sol (2-D vector)
    if(sum == 0 && root->left == NULL && root->right == NULL){
        sol.push_back(path);
    }
    // if left child exists
    if(root->left != NULL){
        path.push_back((root->left)->val);
        putSum(root->left, sol, sum - (root->left)->val, path);
        // Remove last element from path 
        // and move back to parent 
        path.pop_back();
    }
    // if right child exists
    if(root->right != NULL){
        path.push_back((root->right)->val);
        putSum(root->right, sol, sum - (root->right)->val, path);
        // Remove last element from path 
        // and move back to parent 
        path.pop_back();
    }
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    //2-D vector for storing the path to the required sum
    vector<vector<int> > sol;
    //We use a vector path to store the path
    vector<int>path;
   
    if(root == NULL){
        return sol;
    }
     path.push_back(root->val);
    
    putSum(root, sol, sum - root->val, path);
    
    return sol;
}
