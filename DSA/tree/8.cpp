#include<bits/stdc++.h>
using namespace std;
#define bool int
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 
/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum.
 
 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
*/

bool hasPathSum(node* root,int sum)
{
	if(root==NULL)
		return sum==0;

	if(sum==0&&root->left==NULL&&root->right==NULL)
		return true;

	int val=sum-root->data;

	if(root->left)
		return sum||hasPathSum(root->left,val);
	if(root->right)
		return sum||hasPathSum(root->right,val);
	/* even better...
	bool findPath(node *root, int sum){
//return 0 if root is null
if(!root)
return 0;
//check if the sum is satisfying with leaf node
if((sum-root->data)==0 && root->right==NULL && root->left==NULL){
return 1;
}else{
//else checking in left and right sub-trees
return findPath(root->left, sum-root->data) || findPath(root->right, sum-root->data);
}
}

	*/

}



/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
  int sum = 21;
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
  root->left->right = newnode(5);
  root->right->left = newnode(2);
 
  if(hasPathSum(root, sum))
    printf("There is a root-to-leaf path with sum %d", sum);
  else
    printf("There is no root-to-leaf path with sum %d", sum);
 
  //getchar();
  return 0;
}