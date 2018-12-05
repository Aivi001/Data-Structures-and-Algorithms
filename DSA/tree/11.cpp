#include <bits/stdc++.h>
using namespace std;
  
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
    //struct node* parent;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  //node->parent = NULL;       PARENT POINTER IS NOT NEEDED IN THIS TECHNIQUE
   
  return(node);
}
 
struct node* insert(struct node* node, int data)
{
  /* 1. If the tree is empty, return a new,
      single node */
  if (node == NULL)
    return(newNode(data));
  else
  {
    struct node *temp;  
 
    /* 2. Otherwise, recur down the tree */
    if (data <= node->data)
    {    
         temp = insert(node->left, data);
         node->left  = temp;
         //temp->parent= node;
    }
    else
    {
        temp = insert(node->right, data);
        node->right = temp;
        //temp->parent = node;
    }    
  
    /* return the (unchanged) node pointer */
    return node;
  }
} 

struct node* minVal(node* root)
{
	struct node* n=root;
	while(n->left!=NULL)
		n=n->left;

	return n;

}
struct node* inOrderSuccessor(node* root,node* temp)
{
	struct node*successor;
	if(temp->right!=NULL)
		successor= minVal(temp->right);

	else
	{
		successor=NULL;  // important for corner case when no successor has been found
		while(root!=NULL)
			if(temp->data<root->data)
			{
				successor=root;
				root=root->left;
			}
			else if(temp->data>root->data)
				root=root->right;
			else
				break;  // important, since you stop when you reach the node for which the inorder successor is to be found
	} 

	return successor;
}
  //Main to test 
int main()
{
  struct node* root = NULL, *temp, *succ, *min;
 
  //creating the tree given in the above diagram
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 4);
  root = insert(root, 12);
  root = insert(root, 10);  
  root = insert(root, 14);    
  temp = root->left->right->right;
 
  succ =  inOrderSuccessor(root, temp);
  if(succ !=  NULL)
    printf("\nInorder Successor of %d is %d ", temp->data, succ->data);    
  else
    printf("\nInorder Successor doesn't exit");
 
 // getchar();
  return 0;
}