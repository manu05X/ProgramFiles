/*
Clone a Linked List

Given a doubly linked list of integers with one pointer of each node pointing to the next node (just like in a single link list) while the second pointer, however, can point to any node in the list and not just the previous node.

You have to create a copy of this list and return the head pointer of the duplicated list.



Problem Constraints
1 <= length of the list <= 100000

1 <= Value of node <= 100000



Input Format
The only argument given is head pointer of the doubly linked list.



Output Format
Return the head pointer of the duplicated list.



Example Input
Input 1:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1
Input 2:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1


Example Output
Output 1:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1
Output 2:

1 -> 2 -> 3 -> 4 -> 5
random pointer of each node 
1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1


Example Explanation
Explanation 1:

 Just clone the given list.
Explanation 2:

 Just clone the given list

*/


/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/
ListNode* clonelist(ListNode *A) {
    ListNode* curr = A, *temp; 
  
    // insert additional node after 
    // every node of original list 
    while (curr) 
    { 
        temp = curr->next; 
  
        // Inserting node 
        curr->next = new ListNode(curr->val); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = A; 
  
    // adjust the random pointers of the 
    // newly added nodes 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->random = curr->random ?  
                                 curr->random->next : curr->random; 
  
        // move to the next newly added node by 
        // skipping an original node 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    ListNode* original = A, *copy = A->next; 
  
    // save the start of copied linked list 
    temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp;
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
