#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
struct node* left,*right;
};

int leafCnt( struct node* root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return leafCnt(root->left)+leafCnt(root->right);
}

struct node* newNode(int data)
{
	struct node* n=new(struct node);
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}


int main()
{
struct node* root =newNode(1);
root->left	   = newNode(2);
root->right	   = newNode(3);
root->left->left	   = newNode(4);
root->left->right = newNode(5);
root->right->right=newNode(7);
root->right->left=newNode(8);

cout<<"The leaf node count is…"<<leafCnt(root);
return 0;
}