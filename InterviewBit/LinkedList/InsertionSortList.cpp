/*
Insertion Sort List
Asked in: Microsoft Google
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(A == NULL){
        return A;
    }
    
    ListNode* curr = A->next;
    ListNode* temp;
    ListNode* prev = A;
    ListNode* head = A;
    ListNode* check;
    ListNode* checkPrev;
    
    while(curr != NULL){
        temp = curr->next;
        if(curr->val < prev->val){
            check = head;
            checkPrev = NULL;
            while(check != curr){
                if(check->val > curr->val){
                    break;
                }
                checkPrev = check;
                check = check->next;
            }
            if(checkPrev == NULL){
                head = curr;
                curr->next = check;
                prev->next = temp;
                curr = temp;
            }
            else{
                checkPrev->next = curr;
                curr->next = check;
                prev->next = temp;
                curr = temp;
            }
        }
        else{
            prev = curr;
            curr = temp;
        }
    }
    
    return head;
}



/*
void sortedinsert(ListNode*&head,ListNode*newnode)
{
    ListNode*curr;
    if(head==NULL || head->val>=newnode->val)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        curr=head;
        while(curr->next && curr->next->val<newnode->val)
        {
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;
    }
    
}
ListNode* Solution::insertionSortList(ListNode*head) {
    ListNode*sorted=NULL;
    ListNode*curr=head;
    while(curr)
    {
        ListNode*next=curr->next;
        sortedinsert(sorted,curr);
        curr=next;
    }
    head=sorted;
    return head;
}
___________________________________________________________________________

ListNode* Solution::insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    
    ListNode *sorted = NULL;
    ListNode *list = head;
    
    while (list) {
        ListNode *curr = list;
        list = list->next;
        
        if (sorted == NULL || sorted->val > curr->val) {
            curr->next = sorted;
            sorted = curr;
        } else {
            ListNode *tmp = sorted;
            while (tmp) {
                ListNode *c = tmp;
                tmp = tmp->next;
                
                if (c->next == NULL || c->next->val > curr->val) {
                    c->next = curr;
                    curr->next = tmp;
                    break;
                }
            }
        }
    }
    return sorted;
    
}
 
 
 

 
 */
