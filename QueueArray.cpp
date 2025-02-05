#include<iostream>
using namespace std;
class Queue
{
private:
    int queue[100];
    int front,rear;
    int MAX_SIZE;
public:
    Queue(int MaxSize)
    {
        front =-1;
        rear=-1;
        MAX_SIZE=MaxSize;
    }
    void Enqueue(int num)
    {
        if(rear==MAX_SIZE-1)
        {
            cout<<"OVERFOLW"<<endl;
            return;
        }
        if(front==-1&&rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        queue[rear]=num;
    }
    void Dequeue()
    {
        if(front==-1||front>rear)
        {
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        cout<<"dequeued: "<<queue[front]<<endl;
        front++;
    }
    void display()
    {
        if(front==-1||front>rear)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue Elements: ";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};



int main()
{
    Queue q(3);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);


    q.display();
    q.Enqueue(40);

    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();

    q.display();
}
