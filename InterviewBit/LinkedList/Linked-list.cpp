/*
Linked-List
Design and implement a Linked List data structure. A node in a linked list should have the following attributes - an integer value and a pointer to the next node. It should support the following operations:
insert_node(position, value) - To insert the input value at the given position in the linked list.
delete_node(position) - Delete the value at the given position from the linked list.
print_ll() - Print the entire linked list, such that each element is followed by a single space.

Note: 1 <= position <= n where, n is the size of the linked-list.
If an input position does not satisfy the constraint, no action is required.

 Sample Input: 3
i 1 23
i 2 24
p
d 1
p

 Sample Output: 23 24
24
*/


#include<iostream>
using namespace std;

struct Node { 
   int data; 
   struct Node *next; 
};

struct Node *root = NULL;
int size_of_ll = 0;

void print_ll() {
    // Output each element followed by a space
    struct Node *temp = root;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    if (position >= 1 && position <= size_of_ll + 1) {
        struct Node *temp = new Node;
        temp->data = value;
        if (position == 1) {
            temp->next = root;
            root = temp;
        } else {
            int count = 1;
            struct Node *prev = root;
            while(count < position-1) {
                prev = prev->next;
                count++;
            }
            temp->next = prev->next;
            prev->next = temp;
            
        }
        size_of_ll++;
    }
}

void delete_node(int position) {
    // @params position, integer
    if (position >= 1 && position <= size_of_ll) {
        struct Node *temp = NULL;
        if (position == 1) {
            temp = root;
            root = root->next;
        } else {
            int count = 1;
            struct Node *prev = root;
            while(count < position-1) {
                prev = prev->next;
                count++;
            }
            temp = prev->next;
            prev->next = prev->next->next;
        }
        size_of_ll--;
    }
}
