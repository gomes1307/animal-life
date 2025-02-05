#include<iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
int main() {
    node* a = NULL, * b = NULL, * c = NULL;
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

    cout << "The Original Linked List:" << endl;
    node* temp = a;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }


    node* prev = NULL;
    node* current = a;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    a = prev;
    cout << "The Reversed Linked List:" << endl;
    temp = a;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}
