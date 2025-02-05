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
    cout << "Enter value for the first node: ";
    cin >> a->data;
    cout << "Enter value for the second node: ";
    cin >> b->data;
    cout << "Enter value for the third node: ";
    cin >> c->data;
    a->next = b;
    b->next = c;
    c->next = NULL;
    cout<<"The Link List :"<<endl;

    while(a!=NULL)
    {
        cout<<a->data<<endl;
        a=a->next;
        }
    }
