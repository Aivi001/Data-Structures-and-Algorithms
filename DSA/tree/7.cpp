/* Program to find LCA of n1 and n2 using one traversal of Binary Tree.
   It handles all cases even when n1 or n2 is not there in Binary Tree */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* lcaUtil(Node* root,int n1,int n2,bool& v1,bool& v2)
{

	if(root==NULL)
	return NULL;

	if(root->key==n1)
	{
	v1=true;
	return root;
	}

	if(root->key==n2)
	{
	v2=true;
	return root;
	}

	Node* leftLca= lcaUtil(root->left,n1,n2,v1,v2);
	Node* rightLca= lcaUtil(root->right,n1,n2,v1,v2);

	if(leftLca&&rightLca)
		return root;

	if(leftLca!=NULL)
		return leftLca;
	else
		return rightLca;

} 

bool find(Node* lca,int val)
{
	if(lca==NULL)
		return false;

	if(lca->key==val || find(lca->left,val) || find(lca->right,val))
		return true;
}


struct Node* findLca(Node* root,int n1,int n2)
{
	bool v1=false,v2=false;
	Node* lca=lcaUtil(root,n1,n2,v1,v2);

	if(v1&&v2 || v1&&find(lca,n2) || v2&&find(lca,n1))
	return lca;

	return NULL;
}


int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    Node *lca =  findLca(root, 4, 5);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca->key;
    else
       cout << "Keys are not present ";
 
    lca =  findLca(root, 4, 10);
    if (lca != NULL)
       cout << "\nLCA(4, 10) = " << lca->key;
    else
       cout << "\nKeys are not present ";
 
    return 0;
}
