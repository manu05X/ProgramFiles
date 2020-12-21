// Iterative inorder tree traversal algorithm

/*
Using Morris Traversal, we can traverse the tree without using stack and recursion. 
The idea of Morris Traversal is based on Threaded Binary Tree. In this traversal, 
we first create links to Inorder successor and print the data using these links, 
and finally revert the changes to restore original tree. 

1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             Go to the right, i.e. current = curent->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left

*/

//c Style
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}Node;

void insertIntoTree(Node **, int);
Node *createNode(int);
Node *insertData(Node *, int);
void morrisInorderTreeTraversal(Node *);
Node *findPredecessor(Node *);



int main(void){
	Node *root = NULL;
	int data[] = {13, 8, 18, 14, 20, 6, 11};
	for(int i=0; i<7; ++i)	
		insertIntoTree(&root, data[i]);
	morrisInorderTreeTraversal(root);
	return 0;
}


void morrisInorderTreeTraversal(Node *node)
{
	while(node)
	{
		if(!node->left)
		{
			printf("%d ", node->data);
			node = node->right;
		}
		else
		{
			Node *predecessor = findPredecessor(node);

			if(predecessor->right)
			{
				predecessor->right = NULL;
				printf("%d ", node->data);
				node = node->right;
			}
			else
			{
				predecessor->right = node;
				node = node->left;
			}
		}
	}
	return;
}

Node *findPredecessor(Node *node)
{
	Node *temp;
	for(temp = node->left; temp->right && temp->right != node; temp = temp->right);
	return temp;
}


//-------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{
	struct tNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) {

		if (current->left == NULL) {
			printf("%d ", current->data);
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as the right child of its
			inorder predecessor */
			if (pre->right == NULL) 
			{
				pre->right = current; //linking to predecessor
				current = current->left;// giving control to left subtree
			}

			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else {
				pre->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
		 1
		/ \
	   2   3
	  / \
	 4	 5
  */
	struct tNode* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}
