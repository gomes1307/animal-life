#include<iostream>
using namespace std;
struct node
{
  int data;
  node *next;
  node *prev;
};
int main()
{
    node *a=NULL,*b=NULL,*c=NULL,*d=NULL;
    a =new node();
    b =new node();
    c =new node();
    d =new node();

    cout<<"Enter 4 nodes:"<<endl;
    cin>>a->data>>b->data>>c->data>>d->data;
    a->prev=NULL,a->next=b;
    b->prev=a,b->next=c;
    c->prev=b,c->next=d;
    d->prev=c, d->next=NULL;

    cout<<"Forward list:"<<endl;
    node*temp=a;
    for(;temp!=NULL;temp=temp->next)
    {
        cout<<temp->data<<endl;

    }
    cout<<"Backward List:"<<endl;
    temp=d;
    for(;temp!=NULL;temp=temp->prev)
    {
        cout<<temp->data<<endl;

    }
}
