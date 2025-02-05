#include <iostream>
using namespace std;
struct node
{
  int data;
  node*next;
  node*prev;
};
int main() {
    node*a=NULL,*b=NULL,*c=NULL;
    a = new node();
    b = new node();
    c = new node();
    cout<<"Enter 3 nodes: ";
    cin>>a->data>>b->data>>c->data;
    a->next=b;
    a->prev=NULL;

    b->next=c;
    b->prev=a;

    c->next=NULL;
    c->prev=b;
    cout<<"Forward Traversal:"<<endl;
    node*temp=a;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }

     cout<<"Backward Traversal:"<<endl;
     temp=c;
     while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->prev;
    }

    return 0;
}
