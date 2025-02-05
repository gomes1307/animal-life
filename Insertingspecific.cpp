#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
int main() {
    node *a = NULL, *b = NULL, *c = NULL,*d = NULL;
    a = new node();
    b = new node();
    c = new node();
    d = new node();
    cout << "Enter value for the first node: ";
    cin >> a->data;
    cout << "Enter value for the second node: ";
    cin >> b->data;
    cout << "Enter value for the third node: ";
    cin >> c->data;
    cout << "Enter value for the fourth node: ";
    cin >> d->data;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next=NULL;
    cout << "The original linked list:" << endl;
    node* head = a;
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;}
    int position, value;
    cout << "Enter the position to insert the new node (1-based index): ";
    cin >> position;
    cout << "Enter the value for the new node: ";
    cin >> value;
    node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        int count = 1;
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;}
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            //return 1;
            }
        newNode->next = temp->next;
        temp->next = newNode;}
    cout << "The modified linked list:" << endl;
    temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;}
    return 0;
}

