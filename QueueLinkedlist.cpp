#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
};
class Queue {
private:
   Node* front;
   Node* rear;
public:
   Queue () {
   front = NULL;
   rear = NULL;
  }
  void Enqueue (int val) {
   Node* p = new Node ();
   p->data = val;
   p->next = NULL;
   if (front == NULL) {
    front = rear = p;
    } else {
    rear->next = p;
    rear = p;
   }
}
 void Dequeue () {
 if (front == NULL) {
 cout << "Underflow" << endl;
 return;
}
 Node* temp = front;
 cout << "Dequeue: " << front->data << endl;
 front = front->next;
 delete temp;
  }
 void display () {
 if (front == NULL) {
   cout << "Queue is empty" << endl;
    return;
    }
Node* temp = front;
cout << "Queue elements: ";
while (temp != NULL) {
cout << temp->data << " ";
  temp = temp->next;
   }
   cout << endl;
   }
 };
   int main () {
    Queue q;
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

