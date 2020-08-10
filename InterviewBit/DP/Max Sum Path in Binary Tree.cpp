/*
Max Sum Path in Binary Tree
Problem Description

Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.



Problem Constraints
1 <= Number of Nodes <= 7e4

-1000 <= Value of Node in T <= 1000



Input Format
The first and the only argument contains a pointer to the root of T, A.



Output Format
Return an integer representing the maximum sum path.



Example Input
Input 1:

  
    1
   / \
  2   3
Input 2:

       20
      /  \
   -10   20
        /  \
      -10  -50


Example Output
Output 1:

 6
Output 2:

 40


Example Explanation
Explanation 1:

     The path with maximum sum is: 2 -> 1 -> 3
Explanation 2:

     The path with maximum sum is: 20 -> 20
 
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
 int rec(TreeNode *root,int &result)
 {
     if(root==nullptr)
        return 0;
 
 int left=rec(root->left,result);
 int right=rec(root->right,result);
 
 int max_single=max(max(left,right)+root->val,root->val);
 int max_top=max(max_single,left+right+root->val);
 
 result=max(max_top,result);
 
     return max_single;
 }
 
int Solution::maxPathSum(TreeNode* A) {
    int result=INT_MIN;
    rec(A,result);
    
    return result;
    
}




/*
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxAns = INT_MIN;
        maxPathAndGlobalUpdate(root, maxAns);
        return maxAns;
    }

    int maxPathAndGlobalUpdate(TreeNode *root, int &global_max) {
        if (root == NULL) return 0;
        int l = max(0, maxPathAndGlobalUpdate(root->left, global_max));
        int r = max(0, maxPathAndGlobalUpdate(root->right, global_max));
        global_max = max(global_max, l + r + root->val);
        return root->val + max(l, r);
    }
};
________________________________________________________________________________________________________

 //* Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }//
public class Solution {
	public int maxPathSum(TreeNode A) {
	    
	    Node node = rec(A);
	    
	    return node.maxSum;
	    
	}
	
	
	public Node rec(TreeNode node) {
	    
	    if (node == null)
	        return null;
	    
	    if (node.left == null && node.right == null) {
	        Node n = new Node();
	        n.maxSum = node.val;
	        n.maxPath = node.val;
	        return n;
	    }
	    
	    Node left, right, n;
	    
	    left = rec(node.left);
	    right = rec(node.right);
	    n = new Node();
	    
	    if (left == null) {
	        n.maxPath = node.val + right.maxPath;
	        n.maxSum = Math.max(n.maxPath, right.maxSum);
	    } else if (right == null) {
	        n.maxPath = node.val + left.maxPath;
	        n.maxSum = Math.max(n.maxPath, left.maxSum);
	    } else {
	        n.maxPath = Math.max(left.maxPath, right.maxPath) + node.val;
	        n.maxSum = Math.max(n.maxPath, left.maxSum);
	        n.maxSum = Math.max(n.maxSum, right.maxSum);
	        n.maxSum = Math.max(n.maxSum, left.maxPath + right.maxPath + node.val);
	    }
	    
	    n.maxPath = Math.max(node.val, n.maxPath);
	    n.maxSum = Math.max(n.maxSum, n.maxPath);
	    
	    return n;
	    
	}
	
	
	class Node {
	    int maxSum;
	    int maxPath;
	}
	
}

*/