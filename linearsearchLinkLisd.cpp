#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

int main() {
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


    int key;
    cout << "Enter the value to search: ";
    cin >> key;

    node *current = a;
    current = a;


    node *result = NULL;
    while (current != NULL) {
        if (current->data == key) {
            result = current;
            break;
        }
        current = current->next;
    }

    if (result != NULL)
        cout << "Value " << key << " found in the list." << endl;
    else
        cout << "Value " << key << " not found in the list." << endl;
    cout << "The linked list values are:" << endl;
    current = a;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }

    return 0;
}
