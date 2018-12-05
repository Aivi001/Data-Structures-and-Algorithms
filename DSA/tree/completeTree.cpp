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

/*
not crct ,since stops at first node eh stops...
int dCnt(struct node* root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL&&root->right!=NULL)
		return 1;
	else
		return dCnt(root->left)+dCnt(root->right);
}
*/

int halfCnt(struct node* root)
{
	if(root==NULL)
		return 0;
	int cnt=0;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		struct node* temp=new(struct node);
		temp=q.front();
		q.pop();

		if(!temp->left && temp->right || temp->left && !temp->right)
			cnt++;
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	return cnt;

}

int fCnt(struct node* root)
{
	if(root==NULL)
		return 0;
	int cntr=0;

queue<node*>n;
n.push(root);

while(!n.empty())
{
	struct node* temp=n.front();  //not necessary to use new
 	n.pop();

	if(temp->left&&temp->right)
	{	cntr++;
	n.push(temp->left);
	n.push(temp->right);
	}
}
return cntr;
}


struct node* newNode(int data)
{
	struct node* n=new(struct node);
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

//delete a leaf/half node or node with 2 children

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}


struct node* minVal(struct node* root)
{
	struct node* temp=root;
while(temp->left!=NULL)
temp=temp->left;
return	temp;

}


struct node* deleteN(struct node* root,int val)
{
	if(val<root->data)
		root->left=deleteN(root->left,val);
	else if(val>root->data)
		root->right=deleteN(root->right,val);
	else
	{    //one or no chid
		if(root->left==NULL)
		{	struct node* temp=root->right;
			free(root);
			return temp;
		}

		if(root->right==NULL)
		{
			struct node* temp=root->left;
			free(root);
			return temp;
		}
		//two children ...
		struct node* temp=minVal(root->right);
		root->data=temp->data;
		root->right=deleteN(root->right,temp->data);
	}
}


int maxDepth(struct node* root)
{
	if(root==NULL)
		return 0;
	else
	{
		int ldepth= maxDepth(root->left);
		int rdepth=maxDepth(root->right);

if(ldepth>rdepth)
	return ldepth+1;
else
	return rdepth+1;
          }
}

int numNodes(struct node*root)
{
	int c=1;
	if(root==NULL)
		return 0;
	else
	{
			c+=numNodes(root->left);
			c+=numNodes(root->right);
			return c;
	}

}

int minv(struct node* root)
{
	struct node* temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp->data;
}

int maxv(struct node* root)
{
	struct node* temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp->data;
}
//find deepest node
void find(struct node *root, int level, int &maxLevel, int &res)
{
    if (root != NULL)
    {
        find(root->left, ++level, maxLevel, res);

        // Update level and resue
        if (level > maxLevel)
        {
            res = root->data;
            maxLevel = level;
        }

        find(root->right, level, maxLevel, res);
    }
}

// Returns value of deepest node
int deepestNode(struct node* root)
{
    // Initialze result and max level
    int res = -1;
    int maxLevel = -1;

    // Updates value "res" and "maxLevel"
    // Note that res and maxLen are passed
    // by reference.
    find(root, 0, maxLevel, res);
    return res;
}



int main()
{
/*
Dont use for delete...
struct node* root =newNode(1);
root->left	   = newNode(2);
root->right	   = newNode(3);
root->left->left	   = newNode(4);
root->left->right=newNode(5);
root->left->left->right=newNode(8);
root->left->right->right=newNode(9);
//root->left->right = newNode(5);  gives cnt as 2 since , the right is reintialised as NULL
root->right->right=newNode(7);
//root->right->left=newNode(8);
//cout<<"Number of double child nodes... "<<dCnt(root); // O(n) time , O(n) space since stack
cout<<"Number of half nodes is... "<<halfCnt(root)<<"\n";
cout<<"The leaf node count is…"<<leafCnt(root)<<"\n";  //O(n) time , O(n) space since stack
cout<<"Number of nodes with two children are... "<<fCnt(root)<<"\n"; //O(n) time and space
*/
struct node *root = NULL;
   root = insert(root, 50);
   root = insert(root, 30);
   root = insert(root, 20);
   root = insert(root, 40);
   root = insert(root, 70);
   root = insert(root, 60);
   root = insert(root, 80);cout<<"Deleting...\n";  //gives segfault if node val doesnt exist
inorder(root);
cout<<"\n";
root=deleteN(root,80);
inorder(root);
cout<<"\n";
root=deleteN(root,70);
inorder(root);
cout<<"\n";
root=deleteN(root,50);
inorder(root);
cout<<"\n";
//Insertion and deletion have worst case complexity of O(h) h-ht of tree, maybe n if skewed tree

//height of BST
//finding height of BST
cout<<"height of the BST "<<maxDepth(root)<<"\n";  //O(n) time return 3 for 2.
cout<<"Total number of nodes is... "<<numNodes(root)<<"\n";  //total number of nodes , O(n)
cout<<"Least val is "<<minv(root)<<"\n";
cout<<"Max val is "<<maxv(root)<<"\n";
cout<<"Deepest node is "<<deepestNode(root);
return 0;
}

/*iterative find ht involves: first enqueue root,
while(1) then take ncnt,if , ncnt(node count) <0 inc ht , else(ret ht)
while( ncnt>0)  enqueue the q.front() node's left n right child ,dec the cnt of ncnt

*/



/*
2.
           50
		  /   \
		 30   60           (after deletion and for finding ht of BST)
		/  \
	   20  40


              1
			 /   \
			2     3
		   /  \    \
		  4    5    7
		   \    \
		   8     9

		   leaves: 3(8,9,7) , half nodes(single child): 3 (3,4,5), two childeren: 2 (1,2)
*/