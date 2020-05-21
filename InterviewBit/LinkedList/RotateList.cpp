/*
Rotate List
Asked in: Amazon
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* curr = A;
    ListNode* head = A;
    ListNode* last;
    
    int sizeOv = 0;
    
    if(B == 0 || A == NULL){
        return A;
    }
    
    while(curr != NULL){
        last = curr;
        curr = curr->next;
        sizeOv++;
    }
    
    while(B >= sizeOv){
        B = B - sizeOv;
    }
    
    B = sizeOv - B;
    
    last->next = head;
    // now, its a circular list
    
    curr = A;
    
    while(B != 0){
        last = curr;
        curr = curr->next;
        B--;
    }
    
    head = curr;
    last->next = NULL;
    
    return head;
}




/*
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy, *slow = dummy;

        int sizeOfList = 0; 
        while (fast->next != NULL) {
            fast = fast->next;
            sizeOfList++;
        }

        int firstNodePos = sizeOfList - (k % sizeOfList);
        for (int i = 0; i < firstNodePos; i++) {
            slow = slow->next;
        }

        fast->next = dummy->next;
        dummy->next = slow->next; 
        slow->next = NULL;

        return dummy->next;
    }
};
___________________________________________________________________________

ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = 0;
    ListNode* head = A;

    while(head!=NULL)
    {
        n++;
        head = (*head).next;
    }
    B = B%n;
        if(B==n || B==0)
        return A;
        
    ListNode* l2 = A;
    ListNode* l1 = A;
    for(int i=0;i<(n-B);i++)
    {
        l2 = (*l2).next;
    }
    
    for(int i = 0;i<(n-B-1);i++)
    {
        l1 = (*l1).next;
    }
    (*l1).next = NULL;
    ListNode* h = l2;
    for(int i = 0;i<(B-1);i++)
    {
        h = (*h).next;
    }
    (*h).next = A;
    return l2;
}
 
 */
