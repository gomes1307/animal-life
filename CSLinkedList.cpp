#include <iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};
int main()
{
    node*a =NULL,*b=NULL,*c=NULL,*d=NULL;
    a = new node();
     b = new node();
      c = new node();
       d = new node();

       cout<<"Enter 4 node: "<<endl;
       cin>>a->data>>b->data>>c->data>>d->data;
       a->next=b;
       b->next=c;
       c->next=d;
       d->next=a;

node*head=a;
node*temp=head;
cout << "Circular linked list values:" << endl;
       do{
           cout<<temp->data<<" ";
           temp=temp->next;
       }
       while(temp!=head);
}
