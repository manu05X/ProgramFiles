/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 = m = n = length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 struct ListNode* reverse(struct ListNode* head) 
{ 
    struct ListNode* prev = NULL;     
    struct ListNode* curr = head; 
  
    while (curr) { 
        struct ListNode* next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    return prev; 
} 
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (B == C) 
        return A; 
  
    // revs and revend is start and end respectively 
    // of the portion of the linked list which 
    // need to be reversed. revs_prev is previous 
    // of starting position and revend_next is next 
    // of end of list to be reversed. 
    ListNode* revs = NULL, *revs_prev = NULL; 
    ListNode* revend = NULL, *revend_next = NULL; 
  
    // Find values of above pointers. 
    int i = 1; 
    ListNode* curr = A; 
    while (curr && i <= C) { 
        if (i < B) 
            revs_prev = curr; 
  
        if (i == B) 
            revs = curr; 
  
        if (i == C) { 
            revend = curr; 
            revend_next = curr->next; 
        } 
  
        curr = curr->next; 
        i++; 
    } 
    revend->next = NULL; 
  
    // Reverse linked list starting with 
    // revs. 
    revend = reverse(revs); 
  
    // If starting position was not head 
    if (revs_prev) 
        revs_prev->next = revend; 
  
    // If starting position was head 
    else
        A = revend; 
  
    revs->next = revend_next; 
    return A; 
} 

