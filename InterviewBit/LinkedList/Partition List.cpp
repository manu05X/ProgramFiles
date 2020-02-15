/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* c1=NULL,*c2=NULL;
    ListNode* l1=c1,*l2=c2;
    ListNode* temp=A;
    while(temp!=NULL){
        if(temp->val<B){
            if(c1==NULL){
                c1=new ListNode(temp->val);
                l1=c1;
            }
            else{
                l1->next=new ListNode(temp->val);
                l1=l1->next;
            }
        }
        else{
            if(c2==NULL){
                c2=new ListNode(temp->val);
                l2=c2;
            }
            else{
                l2->next=new ListNode(temp->val);
                l2=l2->next;
            }
        }
        ListNode* x=temp;
        temp=temp->next;
        free(x);
        A=temp;
    }
    if(c1==NULL) return c2;
    l1->next=c2;
    return c1;
}

/*
ListNode* Solution::partition(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;
    
    ListNode* fakeHead = new ListNode(0), *temp=A, *last=A;
    fakeHead->next = A;
    A = fakeHead;
    int n =0;
    
    while(temp){
        temp=temp->next;
        n++;
    }
    
    while(last->next){
        last=last->next;
    }
    
    while(n--){
        
        if(fakeHead->next->val <B){
            fakeHead=fakeHead->next;
        }
        
        else{
            last->next = new ListNode(fakeHead->next->val);
            last = last->next;
            fakeHead->next = fakeHead->next->next;
        }
    }
    
    return A->next;
}

java>
public class Solution {
    public ListNode partition(ListNode A, int B) {
        ListNode n1 = new ListNode(0);
        ListNode n2 = new ListNode(0);
        
        ListNode curr1 = n1;
        ListNode curr2 = n2;
        
        while (A != null) {
            if (A.val < B) {
                curr1.next = new ListNode(A.val);
                curr1 = curr1.next;
            }
            else {
                curr2.next = new ListNode(A.val);
                curr2 = curr2.next;
            }
            A = A.next;
        }

        curr1.next = n2.next;
        
        return n1.next;
    }
}


*/

