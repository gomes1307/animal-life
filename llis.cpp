#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
int main() {
    Node* head = NULL;
    int data;
    cout << "Enter data for nodes (enter -1 to stop): ";
    //user input form last to first a->b->c
    while (true) {
        cin >> data;
        if (data == -1) {
            break; }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;}

    cout << "Original list: ";
    //Creating temp for travarsing the list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;}
    cout << endl;
    // user input of position and data
    int Insert, pos;
    cout << "Enter data to insert: ";
    cin >> Insert;
    cout << "Enter position to insert (0-based indexing): ";
    cin >> pos;
    // for beginning
    if (pos == 0) {
        Node* newNode = new Node();
        newNode->data = Insert;
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;}

        Node* newNode = new Node();
        newNode->data = Insert;
        newNode->next = temp->next;
        temp->next = newNode;}
    cout << "List after insertion: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;}
    cout << endl;
     return 0;
}
