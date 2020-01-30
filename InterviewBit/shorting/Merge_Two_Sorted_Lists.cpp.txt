/*
Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists, and should also be sorted. For example, given following linked lists :
  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :
4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B)
{
    ListNode* result = NULL; //new linked list for ans
    //Base case
    if(A == NULL)
        return B;
    else if(B == NULL)
            return A;
     /*Pick either by compyring and then recur*/
     
     if(A->val<= B->val)
     {
         result = A ;    //if condition is true then store A in result
         result->next = mergeTwoLists(A->next, B); // recursion and passing A's next and same B
     }
     else           //executing the else part as if is false
     {
         result = B; //if condition is false then store B in result
         result->next = mergeTwoLists(A, B->next);// recursion and passing B's next and same A
     }
     
     return result;
}