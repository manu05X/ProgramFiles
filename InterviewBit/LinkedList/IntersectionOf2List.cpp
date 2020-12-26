/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
160. Intersection of Two Linked Lists

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if (p1 == NULL || p2 == NULL) return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            //
            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.
            //
            if (p1 == p2) return p1;

            //
            // If one of them reaches the end earlier then reuse it 
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning, 
            // they will be equidistant from the collision point.
            //
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }

        return p1;
    }
};


/*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        ListNode *a = headA;
        ListNode *b = headB;
        //if a & b have diff lenth, then we will stop the loop after second iteration
        while(a != b)
        {
            //for the end of 1st iteration, we just reset the pointer to the head of another linkedlist
            if(a == NULL)
            {
                a = headB;
            }
            else
            {
                a = a->next;
            }
            if(b == NULL)
            {
                b = headA;
            }
            else
            {
                b = b->next;
            }
        }
        return a;
    }
};
___________________________________________________________________________

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *curr1 = headA;
        ListNode *curr2 = headB;
        int count = 0;
        
        while(count < 2)
        {
            if(curr1 == NULL)
            {
                curr1 = headB;
                ++count;
            }            
            else
                curr1 = curr1->next;
            
            if(curr2 == NULL)
            {
                curr2 = headA;
                count++;
            }
            else
                curr2 = curr2->next;
        }
        while (curr1 && curr2) 
        {
            if (curr1 == curr2) 
            {
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return nullptr;
    }
};
 
 */
