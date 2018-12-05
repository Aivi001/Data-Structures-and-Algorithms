#include<bits/stdc++.h>
using namespace std;


struct node
{
  int data;
  struct node* next;

};

int main()
{
int n;
cout<<"Singly Linked List \n~~~~~~~~~~~~~~~~~~~";
//struct node *ll;                      |
//cout<<"Enter the number of nodes\t";  |
//cin>>n;                               |      wrong
//ll=malloc(n*sizeof(struct list));     |
struct node* head=new(struct node);
struct node* second=new(struct node);
struct node* third=new(struct node);

head->next=second;
second->next=third;
third->next=NULL;
head->data=3;
second->data=2;
third->data=5;

struct node* temp=new(struct node);
temp=head;

while(temp!=NULL)
{
cout<<"DATA"<<temp->data<<"\n";
temp=temp->next;
}
cout<<endl;
cout<<third->data;
/*struct node *temp;
temp=new(struct node);

if(temp==NULL)
  cout<<"No memory allocated";

else
{
cout<<"Enter value... ";
int val;
cin>>val;
temp->data=val;
temp->next=NULL;
}
cout<<"Only node's value is "<<temp->data;
*/
return 0;
}