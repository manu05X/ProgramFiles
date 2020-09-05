/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
1305. All Elements in Two Binary Search Trees
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    
public:
    // inorder Traversal
    void inOrderTraversal(TreeNode* root, vector<int> &v)
    {
        if(root == NULL)
        {
            return;
        }
        inOrderTraversal(root->left, v);
            v.push_back(root->val);
        inOrderTraversal(root->right, v);
    }
    // Mergeing the two Vector
    vector<int> merge( vector<int> v1,  vector<int> v2)
    {
        vector<int> ans;
        int start1 = 0;
        int start2 = 0;
        
        int len1 = v1.size();
        int len2 = v2.size();
        
        while(len1 > start1 && len2 > start2)
        {
            if(v1[start1] <= v2[start2])
            {
                ans.push_back(v1[start1]);
                start1++;
            }
            else
            {
                ans.push_back(v2[start2]);
                start2++;
            }
        }
        while(len2 > start2)
        {
            ans.push_back(v2[start2]);
            start2++;
        }
        
        while(len1 > start1)
        {
            ans.push_back(v1[start1]);
            start1++;
        }
        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> v1;
        inOrderTraversal(root1, v1);    //STEP: 1 Inorder Traversal and keeping element in v1
        
        vector<int> v2;             
        inOrderTraversal(root2, v2);    //STEP: 1 Inorder Traversal and keeping element in v2
        
        return merge(v1, v2);           //STEP: 2 Merging the v1 and v2
    }
};