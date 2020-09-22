/*
Given an N-ary tree, find the subtree with the maximum average. Return the root of the subtree.
A subtree of a tree is the node which have at least 1 child plus all its descendants. The average value of a subtree is the sum of its values, divided by the number of nodes.

Example 1:

Input:
		 20
	   /   \
	 12     18
  /  |  \   / \
11   2   3 15  8

Output: 18
Explanation:
There are 3 nodes which have children in this tree:
12 => (11 + 2 + 3 + 12) / 4 = 7
18 => (18 + 15 + 8) / 3 = 13.67
20 => (12 + 11 + 2 + 3 + 18 + 15 + 8 + 20) / 8 = 11.125

18 has the maximum average so output 18.

// amazone

//Similar questions:

https://leetcode.com/problems/maximum-average-subtree
*/

//(1) C++ Solution for N-ary question

class Solution {
public:
    struct node{
        double sum;
        double count;
    };
    double max_val, ans=0;
    
    node avgHelper(TreeNode* root){
        if(root==nullptr) return {0, 0};
        
        node curr={root->val, 1};
        for(int i=0; I<root->child.size(); i++){
             node child=avgHelper(root->child[i]);
             curr.sum+=child.sum;
             curr.count+=child.count;
       }

        if(max_val < (double)(curr.sum/curr.count)){
                max_val=(double)(curr.sum/curr.count);
                ans=root->val;
       }
        
        return curr;
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        avgHelper(root);
        return ans;
    }
};
//(2) C++ Solution for BT question

class Solution {
public:
    struct node{
        double sum;
        double count;
    };
    double max_val;
    
    node avgHelper(TreeNode* root){
        if(root==nullptr) return {0, 0};
        
        node left=avgHelper(root->left);
        node right=avgHelper(root->right);
        node curr={left.sum + right.sum + root->val, left.count + right.count + 1};
        
        max_val=max(max_val, (double)(curr.sum/curr.count));
        
        return curr;
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        avgHelper(root);
        return max_val;
    }
};