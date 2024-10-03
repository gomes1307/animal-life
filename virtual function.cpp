#include<iostream>
using namespace std;
class B
{
public:
 virtual void display()
    {
        cout<<"hi"<<endl;
    }
};
class D:public B
{
public:
    void display()
    {
        cout<<"hello"<<endl;
    }
};
int main()
{
    B ob1;
    ob1.display();
    D ob;
    B* ptr;
    ptr=&ob;
    ptr->display();

    return 0;
}
