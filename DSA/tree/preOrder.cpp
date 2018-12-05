#include<bits/stdc++.h>
using namespace std;
map<int,struct node*>lvls;

struct node
{

int data;
struct node* left;
struct node* right;

};

struct node* newNode(int key)
{

struct node* temp=new node;
temp->data=key;
temp->left=temp->right=NULL;
return temp;
}


struct node* insert(struct node* root,int key)
{

	if(root==NULL)
	return newNode(key);

	if(key<root->data)
	root->left=insert(root->left,key);

	else if(key>root->data)
	root->right=insert(root->right,key);

	else;

	return root;
}

int minVal(struct node*root)
{

	while(root->left!=NULL)
		root=root->left;
	return root->data;

}

struct node* deleteNode(struct node* root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->data)
	 root->left=deleteNode(root->left,key);
	else if(key>root->data)
	 root->right=deleteNode(root->right,key);

	else
	{

		if(root->left==NULL)
		{
			return root->right;
			//root->data=root->right->data;
			//free(root->right);
			//root->right=NULL;
		}


		else if(root->right==NULL)
		{
			

			struct node* temp=root->left;
			free(root);
			return temp;
//root->data=root->left->data;          //iterative approach has segFault
			//free(root->left);
			//root->left==NULL;
			

		}

	
		else{

		int val=minVal(root->right);
		root->data=val;
		root->right=deleteNode(root->right,val);




		}



	}

return root;



}

void preOrder(struct node* root)
{

	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node* root)
{

	if(root==NULL)
	return;
	preOrder(root->left);
	preOrder(root->right);
	cout<<root->data<<" ";
}

void inOrder(struct node* root)
{

	if(root==NULL)
	return;
	preOrder(root->left);
	cout<<root->data<<" ";
	preOrder(root->right);
}

void level(struct node* root)
{
	struct node* temp;
	queue<struct node*>Q;
	Q.push(root);

	while(!Q.empty())
	{

		temp=Q.front();
		Q.pop();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
			Q.push(temp->left);
		if(temp->right!=NULL)
			Q.push(temp->right);

	}


}


void leftView(struct node* root)
{

	queue<struct node*>Q;
	struct node* temp=new node;
	int s,i;

	Q.push(root);

	s=Q.size();

	while(!Q.empty())
{	
	s=Q.size();
	for(i=0;i<s;i++)
	{
		temp=Q.front();
		Q.pop();
		if(i==0)
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
			Q.push(temp->left);
		if(temp->right!=NULL)
			Q.push(temp->right);

	}

}


}


void rightView(struct node* root)
{

	queue<struct node*>Q;
	struct node* temp=new node;
	int s,i;

	Q.push(root);

	s=Q.size();

	while(!Q.empty())
{	
	s=Q.size();
	for(i=0;i<s;i++)
	{
		temp=Q.front();
		Q.pop();
		if(i==s-1)
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
			Q.push(temp->left);
		if(temp->right!=NULL)
			Q.push(temp->right);

	}

}


}

void topView(struct node* root,int level)
{

	if(lvls.find(level)==lvls.end()) // also, lvls[level]==NULL  O(1)
		{
		lvls[level]=root;
		cout<<root->data<<" ";
		}
	
	if(root->left!=NULL)
		topView(root->left,level-1);
	if(root->right!=NULL)
		topView(root->right,level+1);
}

void bottomView(struct node*root)
{

	if(root==NULL)
	return ;
	
	int hd=0;

	map<int ,int>m;

	queue< pair < struct node*,int > >Q;

	Q.push(make_pair(root,0));

	while(!Q.empty())

	{
		pair < struct node*,int >temp =Q.front();
		Q.pop();
		struct node* n=temp.first;
		int val=temp.second; 

		m[temp.second]=temp.first->data;

		if(temp.first->left!=NULL)
			Q.push(make_pair(temp.first->left,temp.second-1));
		if(n->right!=NULL)
			Q.push(make_pair(n->right,val+1));
	}
	
		for(auto i=m.begin();i!=m.end();i++)
		cout<<i->second<<" ";


}


int search(struct node* root,int key)    //this is cleaner and segfault free
{
	if(root!=NULL)
{
if(key==root->data)
		return 1;
	else 
		return(search(root->right,key)||search(root->left,key));
	 
}
	return 0;

}

int main()
{

struct node* roo=NULL;
roo=insert(roo,50);
insert(roo,30);
insert(roo,20);
insert(roo,40);
insert(roo,70);
insert(roo,60);
insert(roo,80);

preOrder(roo);
cout<<"\n\n";
inOrder(roo);
cout<<"\n\n";
postOrder(roo);
cout<<"\n\n";
level(roo);
cout<<"\n\n";

if(search(roo,70))
cout<<"Yes\n";
else
cout<<"No\n";

if(search(roo,100))
cout<<"Yes\n";
else
cout<<"No\n";

//deleteNode(roo,70);
if(search(roo,70))
cout<<"Yes\n";
else
cout<<"No\n";

leftView(roo);

//level(roo);
cout<<"\n\nRIGHT View\n";
rightView(roo);
cout<<"\n\nTop view";
topView(roo,0);
cout<<"\n\nBOTTOM view\n";
bottomView(roo);
cout<<"\n\n";


return 0;
}