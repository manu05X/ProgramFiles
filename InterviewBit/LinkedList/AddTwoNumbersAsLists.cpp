/*
Add Two Numbers as Lists

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
     if(A == NULL){
        return B;
    }
    else if(B == NULL){
        return A;
    }
    
    // reversing the list
    
    ListNode* currA = A;
    ListNode* currB = B;
    
    ListNode* ans = NULL;
    ListNode* head;
    
    int sum, carry = 0, value;
    while(currA != NULL && currB != NULL){
        sum = currA->val + currB->val + carry;
        carry = sum/10;
        value = sum%10;
        
        ListNode* store = new ListNode(value);
        
        if(ans == NULL){
            ans = store;
            head = ans;
        }
        else{
            ans->next = store;
            ans = store;
        }
        currA = currA->next;
        currB = currB->next;
    }
    
    if(currA == NULL){
        while(currB != NULL){
            sum = currB->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currB = currB->next;
        }
    }
    else if(currB == NULL){
        while(currA != NULL){
            sum = currA->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currA = currA->next;
        }
    }
    
    if(carry != 0){
        ListNode* store = new ListNode(carry);
        
        ans->next = store;
        ans = store;
    }

    return head;
}




/*
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return B;
    }
    else if(B == NULL){
        return A;
    }
    
    // reversing the list
    
    ListNode* currA = A;
    ListNode* currB = B;
    
    ListNode* ans = NULL;
    ListNode* head;
    
    int sum, carry = 0, value;
    while(currA != NULL && currB != NULL){
        sum = currA->val + currB->val + carry;
        carry = sum/10;
        value = sum%10;
        
        ListNode* store = new ListNode(value);
        
        if(ans == NULL){
            ans = store;
            head = ans;
        }
        else{
            ans->next = store;
            ans = store;
        }
        currA = currA->next;
        currB = currB->next;
    }
    
    if(currA == NULL){
        while(currB != NULL){
            sum = currB->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currB = currB->next;
        }
    }
    else if(currB == NULL){
        while(currA != NULL){
            sum = currA->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currA = currA->next;
        }
    }
    
    if(carry != 0){
        ListNode* store = new ListNode(carry);
        
        ans->next = store;
        ans = store;
    }

    return head;
}
___________________________________________________________________________

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if(!l1)
                return l2;
            if(!l2)
                return l1;

            int carry = (l1->val + l2->val) / 10;
            ListNode *l3 = new ListNode((l1->val + l2->val) % 10);
            ListNode *tail = l3;
            l1 = l1->next;
            l2 = l2->next;

            while(l1 || l2 || carry)
            {
                int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
                ListNode *t  = new ListNode(sum % 10);
                carry = sum / 10;                                          

                if(l1)
                    l1 = l1->next;
                if(l2)
                    l2 = l2->next;
                tail->next = t;
                tail = t;
            }

            return l3;
        }
};
 
 */
