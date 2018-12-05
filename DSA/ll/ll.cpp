#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
struct node* next;
};

struct node* newNode(int key)
{
	struct node* temp=new node;
	temp->data=key;
	temp->next=NULL;
	return temp;

}

void insert_front(struct node** head,int key)
{

struct node* temp=newNode(key);
if(head==NULL)
{
	cout<<"Inserting first elem\n";
	*head=temp;
	return;
}	
temp->next=*head;
*head=temp;

}

void insert_last(struct node** head,int key)
{

struct node* temp=*head;
struct node* temp1=newNode(key);

if(temp==NULL)
	{
		*head=temp1;
		return;
	}

while(temp->next!=NULL)
	temp=temp->next;

temp->next=temp1;

}

void insertAfterPos(struct node** head,int val,int key)
{

	struct node* temp1=newNode(key);
	struct node* temp=*head;
	
	if(temp==NULL)
	{
		*head=temp1;
		return;

	}

	while(temp->data!=val&&temp->next!=NULL)  //don't give cond as temp!=NULL , gives segFault
		temp=temp->next;
	
	if(temp->data!=val)    //don't have the cond as, temp==NULL
	{ cout<<"No such element\n"; 
	return;
	}

	temp1->next=temp->next;
	temp->next=temp1;

	

}

void insertBeforePos(struct node** head,int val,int key)
{

	struct node* temp1=newNode(key);
	struct node* temp=*head;

	if(temp==NULL)
	{
		*head=temp1;
		return;

	}	

	while(temp->next->data!=val&&temp->next!=NULL)  //don't give cond as temp!=NULL , gives segFault
		temp=temp->next;
	
	/*if(temp->next==NULL||temp->next->data!=val)    //don't have the cond as, temp==NULL
	{ cout<<"No such element\n"; 
	return;
	}*/

	temp1->next=temp->next;
	temp->next=temp1;

	

}

void deleteNode(struct node**head,int val)
{

if(*head==NULL)
	{
		cout<<"Empty list\n";
		return;

	}
	struct node* temp=*head;

	while(temp->next->data!=val&&temp->next!=NULL)  //don't give cond as temp!=NULL , gives segFault
		temp=temp->next;

	temp->next=temp->next->next;

}

void reverseList(struct node** head)
{

struct node* curr=*head;
struct node* prev=NULL;
struct node* net=NULL;

while(curr!=NULL)
{
	net=curr->next;  //don't place it after curr->next=prev and as net=net->next;
	curr->next=prev;
	prev=curr;
	curr=net;	
}
*head=prev;
}

void display(struct node* head)
{
struct node* temp=head;

while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}


int main()
{

struct node* head=NULL;
insert_front(&head,50);
insert_front(&head,60);
display(head);
insert_last(&head,70);
insert_last(&head,80);
display(head);
insertAfterPos(&head,90,10);
display(head);
insertAfterPos(&head,70,90);
display(head);
insertBeforePos(&head,70,10);
display(head);
deleteNode(&head,10);
display(head);
reverseList(&head);
display(head);
//insertBeforePos(&head,100,10);  segFault
//display(head);



return 0;
}