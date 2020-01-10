/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) 
{
    ListNode* temp = A;
    stack<int> s;
    
    while(temp!= NULL)
    {
        s.push(temp->val);
        temp =temp->next;
    }
    
    while(A!=NULL)
    {
        int i = s.top();
        s.pop();
        
        if(A->val!=i)
        {
            return 0;
        }
        A=A->next;
    }
    return 1;
}
