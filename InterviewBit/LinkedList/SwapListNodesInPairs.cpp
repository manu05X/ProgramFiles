/*
Swap List Nodes in pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.



*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return A;
    }
    
    ListNode* curr = A;
    ListNode* ahead = curr->next;
    if(ahead == NULL){
        return A;
    }
    ListNode* ans = ahead;
    ListNode* temp;
    ListNode* prev = NULL;
    
    while((curr != NULL) && (ahead != NULL)){
        temp = ahead->next;
        curr->next = temp;
        ahead->next = curr;
        if(prev != NULL){
            prev->next = ahead;
        }
        prev = curr;
        curr = curr->next;
        if(curr != NULL){
            ahead = curr->next;    
        }
    }
    
    return ans;
}




/*
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* prev = A;
    if (prev == NULL) return A;
    ListNode* curr = A->next;
    if (curr == NULL) return A;
    ListNode* next = A->next->next;
    ListNode* lastPrevious = NULL;
    ListNode* ans = curr;
    while(curr != NULL) {
        // if (prev != NULL) cout << "prev->val: " << prev->val << " ";
        // if (curr != NULL) cout << "curr->val: " << curr->val << " ";
        // if (next != NULL) cout << "next->val: " << next->val;
        // cout << endl;
        prev->next = next;
        curr->next = prev;
        if (lastPrevious == NULL) {
            ans = curr;
        } else {
            lastPrevious->next = curr;
        }
        if (next != NULL) {
            lastPrevious = prev;
            prev = next;
            curr = prev->next;
            if (curr != NULL) {
                next = curr->next;
            } else {
                next = NULL;
            }
        } else {
            break;
        }
    }
    return ans;
}
___________________________________________________________________________

ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* prev = A;
    if (prev == NULL) return A;
    ListNode* curr = A->next;
    if (curr == NULL) return A;
    ListNode* next = A->next->next;
    ListNode* lastPrevious = NULL;
    ListNode* ans = curr;
    while(curr != NULL) {
        // if (prev != NULL) cout << "prev->val: " << prev->val << " ";
        // if (curr != NULL) cout << "curr->val: " << curr->val << " ";
        // if (next != NULL) cout << "next->val: " << next->val;
        // cout << endl;
        prev->next = next;
        curr->next = prev;
        if (lastPrevious == NULL) {
            ans = curr;
        } else {
            lastPrevious->next = curr;
        }
        if (next != NULL) {
            lastPrevious = prev;
            prev = next;
            curr = prev->next;
            if (curr != NULL) {
                next = curr->next;
            } else {
                next = NULL;
            }
        } else {
            break;
        }
    }
    return ans;
}
 
 */
