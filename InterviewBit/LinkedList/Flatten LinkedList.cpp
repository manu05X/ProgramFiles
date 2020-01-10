/*
Flatten a linked list
Given a linked list where every node represents a linked list and contains two pointers of its type:
Pointer to next node in the main list (right pointer)
Pointer to a linked list where this node is head (down pointer). All linked lists are sorted.
You are asked to flatten the linked list into a single list. Use down pointer to link nodes of the flattened list. The flattened linked list should also be sorted. 
Input Format
The only argument given is head pointer of the doubly linked list.
Output Format
Return the head pointer of the Flattened list. 
Constraints
1 <= Total nodes in the list <= 100000
1 <= Value of node <= 10^9
For Example
Input 1:
       3 -> 4 -> 20 -> 20 ->30
       |    |    |     |    |
       7    11   22    20   31
       |               |    |
       7               28   39
       |               |
       8               39

Output 1:
3 -> 4 -> 7 -> 7 -> 8 -> 11 -> 20 -> 20 -> 20 -> 22 -> 28 -> 30 -> 31 -> 39 -> 39 
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};

ListNode* merge( ListNode* a, ListNode* b ) 
{ 
    // If first list is empty, the second list is result 
    if (a == NULL) 
        return b; 
  
    // If second list is empty, the second list is result 
    if (b == NULL) 
        return a; 
  
    // Compare the data members of head nodes of both lists 
    // and put the smaller one in result 
    ListNode* result; 
    if (a->val < b->val) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    } 
  
    return result; 
} 


ListNode* flatten (ListNode* root) 
{
    if (root == NULL || root->right == NULL) 
        return root; 
  
    // Merge this list with the list on right side 
    return merge( root, flatten(root->right) ); 
} 

int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
ListNode *head=NULL;
ListNode *prev=NULL;
for(int i=0; i<n; ++i){
int m;
cin>>m;
ListNode *prev1=NULL;
while(m--){
int x;
cin>>x;
ListNode *temp=new ListNode(x);
if(head==NULL)
head=temp;

if(prev1==NULL){
if(prev)prev->right=temp;
prev=temp;
}
else prev1->down=temp;
prev1=temp;
}
}

ListNode *flat=flatten(head);
ListNode *temp=flat;
int yy=0;
while(temp){
if(yy)cout<<"-> ";
cout<<temp->val<<" ";
temp=temp->down;
yy=1;
}
temp=flat;
while(temp){
flat=temp->down;
delete(temp);
temp=flat;
}
cout<<"\n";
}
return 0;}
