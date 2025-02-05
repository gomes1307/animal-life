#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
int main() {
    node *a = NULL, *b = NULL, *c = NULL, *d = NULL;
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
    d->next = NULL;

    cout << "The original linked list:" << endl;
    node* head = a;
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    int position;
    cout << "Enter the position of the node to delete (1-based index): ";
    cin >> position;

    if (position == 1) {
        temp = head;
        head = head->next;
        delete temp;
    } else {
        temp = head;
        int count = 1;
        node* prev = NULL;
        while (temp != NULL && count < position) {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return 1;
        }

        prev->next = temp->next;
        delete temp;
    }

    cout << "The modified linked list:" << endl;
    temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }

    return 0;
}
