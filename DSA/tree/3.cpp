// C++ program to check if two trees are mirror
// of each other
#include<bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node
{
    int data;
    Node* left, *right;
};
 

bool areMirror(Node* r1,Node* r2)
{
	if(r1==NULL&&r2==NULL)
		return true;

	else if(r1==NULL||r2==NULL)
		return false;
	else
		return ((r1->data==r2->data)&&areMirror(r1->left,r2->right)&&areMirror(r1->right,r2->left));	
	



}


Node* newNode(int data)
{
    Node* node = new Node;
    node->data  = data;
    node->left  =  node->right  = NULL;
    return(node);
}
 
/* Driver program to test areMirror() */
int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
 
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);
 
    areMirror(a, b)? cout << "Yes" : cout << "No";
 
    return 0;
}
