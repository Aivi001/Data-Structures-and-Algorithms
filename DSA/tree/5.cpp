/* C program to check if a tree is height-balanced or not */
#include<bits/stdc++.h>
 using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/* Returns the height of a binary tree */
int height(node* n)
{
	if(n==NULL)
		return 0;
	return 1 + max(height(n->left),height(n->right));
}


int isBalanced(node* n)
{
	int lh,rh;
	if(n==NULL)
		return 1;

	lh=height(n->left);
	rh=height(n->right);

	return (abs(lh-rh)<2)&&isBalanced(n->left)&&isBalanced(n->right);

}




/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}
 
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    //root->left->left->left = newNode(8);
 
    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    
 
     return 0;
}