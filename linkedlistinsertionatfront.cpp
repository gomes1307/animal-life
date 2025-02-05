#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node*next; };
int main()
{
    node *a = NULL, *b = NULL, *c = NULL;
    a = new node();
    b = new node();
    c = new node();
    cout << "Enter value for 3 nodes: "<<endl;
    cin >> a->data>>b->data>>c->data;
    a->next = b;
    b->next = c;
    c->next = NULL;
    cout<<"The Link List :"<<endl;
     node*head=a;
     node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
        }
        node*p=new node();
        cout<<"Enter a new node:"<<endl;
        cin>>p->data;
        p->next=head;
        head=p;
        cout<<"After insertion: "<<endl;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }

    }

