#include<iostream>
using namespace std;
class Stack
{
private:
    int stack[100];
    int top;
    int MAX_SIZE;
public:
    Stack(int MaxSize)
    {
        MAX_SIZE=MaxSize;
        top =-1;
    }
    void push(int element)
    {
        if(top==MAX_SIZE-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        stack[++top]=element;
        cout<<"Pushed "<<element<<endl;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<"Popped "<<stack[top--]<<endl;
    }
    void display()
    {
        if(top==-1)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        cout<<"Stack Element: "<<endl;
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack stack(3);
    stack.display();

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.display();

    stack.pop();
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
}
