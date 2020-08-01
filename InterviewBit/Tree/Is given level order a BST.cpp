/*
Is given level order a BST?
Given an distinct integer array A of size N. You have to check whether the given array can represent the level order traversal of a Binary Search Tree or not.

Input Format:

    First and only argument of input is an integer array A
Output Format:

    return 1 if A can represent level order traversal of a BST, 0 otherwise.
Constraints:

    1 <= N <= 100000
    1 <= A[i] <= 10^9
    All integer in array are distinct
Example:

Input 1:
    A = [7, 4, 12, 3, 6, 8, 1, 5, 10]
Output 1:
    1
Explanation 1:
    Following Bst have same level order.
         7        
        / \       
      4    12      
     / \   /     
    3   6 8    
   /   /   \
  1   5    10
Input 2:
    A = [ 2, 3, 4, 1]
Output 2:
    0
 
 
*/

//sol->

struct NodeDetails 
{ 
    int data; 
    int min, max; 
}; 

int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    
    if (n == 0) 
        return true; 
      
    // queue to store NodeDetails 
    queue<NodeDetails> q; 
      
    // index variable to access array elements 
    int i=0; 
      
    // node details for the  
    // root of the BST 
    NodeDetails newNode; 
    newNode.data = arr[i++]; 
    newNode.min = INT_MIN; 
    newNode.max = INT_MAX; 
    q.push(newNode); 
      
    // until there are no more elements  
    // in arr[] or queue is not empty 
    while (i != n && !q.empty())         
    { 
        // extracting NodeDetails of a 
        // node from the queue 
        NodeDetails temp = q.front(); 
        q.pop(); 
          
        // check whether there are more elements  
        // in the arr[] and arr[i] can be left child  
        // of 'temp.data' or not  
        if (i < n && (arr[i] < temp.data &&  
                     arr[i] > temp.min)) 
        { 
            // Create NodeDetails for newNode  
            /// and add it to the queue 
            newNode.data = arr[i++]; 
            newNode.min = temp.min; 
            newNode.max = temp.data; 
            q.push(newNode);                 
        } 
          
        // check whether there are more elements  
        // in the arr[] and arr[i] can be right child  
        // of 'temp.data' or not  
        if (i < n && (arr[i] > temp.data &&  
                      arr[i] < temp.max)) 
        { 
            // Create NodeDetails for newNode  
            /// and add it to the queue 
            newNode.data = arr[i++]; 
            newNode.min = temp.data; 
            newNode.max = temp.max; 
            q.push(newNode);             
        }         
    } 
      
    // given array represents level 
    // order traversal of BST 
    if (i == n) 
        return true; 
          
    // given array do not represent  
    // level order traversal of BST     
    return false; 
}
