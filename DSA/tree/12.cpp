/* program for boundary traversal of a binary tree */
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left, *right;
};
 

void printLeft(struct node* root)
{
	if(root!=NULL)
	{
	if(root->left)
	{
		cout<<root->data<<" ";
		root=root->left;
	}
	else if(root->right)
	{
		cout<<root->data<<" ";
		root=root->right;
	}

	}
}

void printLeaf(struct node* root)
{
	if(root)
	{
	printLeaf(root->left);

	if(!root->left&&!root->right)
		cout<<root->data<<" ";

	printLeaf(root->right);
	}
}

void printRight(struct node* root)
{
	if(root!=NULL)
	{
	if(root->right)
	{
		cout<<root->data<<" ";  //earlier, root->right->data WA
		root=root->right;
	}
	else if(root->left)
	{
		cout<<root->data<<" ";
		root=root->left;
	}

	}
}


void printBoundary(struct node* root)
{
	if(root)
	{
		cout<<root->data<<" "; // important as you need to print the root as well!!
	printLeft(root->left);
	printLeaf(root->left);
	printLeaf(root->right);
	printRight(root->right);
	}
}

 struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printBoundary( root );
 
    return 0;
}