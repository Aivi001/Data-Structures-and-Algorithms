// C program to find sum of all paths from root to leaves
#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int data;
    struct node *left, *right;
};
 
// function to allocate new node with given data
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int treePathsSum(node* root,int val)
{
	if(root==NULL)
		return 0;

	//val=val+root->data;
	val=val*10+root->data;

	if(root->left==NULL&&root->right==NULL)
	{
		//cout<<val<<"\n";
		return val;
	}
	return treePathsSum(root->left,val)+treePathsSum(root->right,val);
}

 
 int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(3);
    root->right       = newNode(5);
    root->left->left  = newNode(2);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    cout<<"Sum of all paths is "<<treePathsSum(root,0);
    return 0;
}