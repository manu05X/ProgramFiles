/*
Remove Zero Sum Sequences from Linked List
Problem Description

Given a Linked list A of length N, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.

NOTE:

If thery are mutiple consecutive sequences to delete then the sequence which occurs first will be deleted first and so on.



Problem Constraints
1 <= N <= 105

-103 <= Value in Each Link List <= 103



Input Format
First argument is the head pointer of the linkedlist.



Output Format
Return the head pointer of the final linkedlist as described.



Example Input
Input 1:

 3 -> 4 -> -7 -> 5 -> -6 -> 6
Input 2:

 1 -> 4 -> 6 -> -6 -> -4 -> 10
Input 3:

 1 -> -1


Example Output
Output 1:

 5
Output 2:

 1 -> 10
Output 3:

 


Example Explanation
Explanation 1:

 You first remove 3 -> 4 -> -7 and then -6 -> 6 leaving only 1
Explanation 2:

 There can be multiple answers like:
    If we delete 4 -> 6 -> -6 -> -4 then we get 1 -> 10 as the answer.
    If we delete -6 -> -4 -> 10 we get 1 -> 4 -> 6 as the answer.

    But in question it is given that delete the sequence which occurs first 
    so 4 -> 6 -> -6 -> -4 occurs first so we will remove it  and output will be 1 -> 10.
Explanation 3:

 Removing 1 -> -1 as it sums to zero. We will return a empty linked list.
 
 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* head) 
{
     ListNode* dummy = new ListNode(0);
      dummy->next = head;
      unordered_map <int, ListNode*> m;
      m[0] = dummy;
      int sum = 0;
      while(head)
      {
         sum += head->val;
         m[sum] = head;
         head = head->next;
      }
      head = dummy;
      sum = 0;
      while(head)
      {
         sum += head->val;
         ListNode* temp = m[sum];
         if(temp != head){
            head->next = temp->next;
         }
         head = head->next;
      }
      return dummy->next;
}


/*

ListNode* Solution::solve(ListNode* head) {
        map<int, ListNode*> hashMap;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        hashMap[0] = dummyNode;
        int sum = 0;
        while(head) {
            sum += head->val;
            if (hashMap.find(sum) == hashMap.end()) hashMap[sum] = head;
            else {
                ListNode* node = hashMap[sum]; ListNode* tail;
                tail = node->next;
                int temp_sum = sum;
                while (tail != head) {
                    temp_sum += tail->val;
                    hashMap.erase(temp_sum);
                    tail = tail->next;
                }
                node->next = tail->next;
            }
            head = head->next;
        }
        return dummyNode->next;
}
*/
