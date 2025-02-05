#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    void Enqueue(int val) {
        Node* p = new Node();
        p->data = val;
        p->next = NULL;

        if (front == NULL) {
            front = rear = p;
            rear->next = front;
        } else {
            rear->next = p;
            rear = p;
            rear->next = front;
        }
    }

    void Dequeue() {
        if (front == NULL) {
            cout << "Underflow" << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeue: " << front->data << endl;

        if (front == rear) {

            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;
        }

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    return 0;
}
