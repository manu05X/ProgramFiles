/*
Length of longest palindromic list
Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list. Note: A palindrome list is a list that reads the same backward and forward. Expected memory complexity : O(1) 
Input Format
The only argument given is head pointer of the linked list.
Output Format
Return the length of the longest palindrome list.
Constraints
1 <= length of the linked list <= 2000
1 <= Node value <= 100 
For Example
Input 1:
    2 -> 3 -> 3 -> 3
Output 1:
   3 

Input 2:
    A = 2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2
Output 2:
    5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // function for counting the common elements 
int countCommon(ListNode *a, ListNode *b) 
{ 
    int count = 0; 
  
    // loop to count coomon in the list starting 
    // from node a and b 
    for (; a && b; a = a->next, b = b->next) 
  
        // increment the count for same values 
        if (a->val == b->val) 
            ++count; 
        else
            break; 
  
    return count; 
} 
  
// Returns length of the longest palindrome 
// sublist in given list 
int maxPalindrome(ListNode *head) 
{ 
    int result = 0; 
    ListNode *prev = NULL, *curr = head; 
  
    // loop till the end of the linked list 
    while (curr) 
    { 
        // The sublist from head to current 
        // reversed. 
        ListNode *next = curr->next; 
        curr->next = prev; 
  
        // check for odd length palindrome 
        // by finding longest common list elements 
        // beginning from prev and from next (We 
        // exclude curr) 
        result = max(result, 2*countCommon(prev, next)+1); 
  
        // check for even length palindrome 
        // by finding longest common list elements 
        // beginning from curr and from next 
        result = max(result, 2*countCommon(curr, next)); 
  
        // update prev and curr for next iteration 
        prev = curr; 
        curr = next; 
    } 
    return result; 
}
 
int Solution::solve(ListNode* A) 
{
    
    return maxPalindrome(A);
    
}