#include<iostream>
using namespace std;
class A
{
    int x,y;
public:
    A(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
    void display()
    {
        cout<<" "<<x<<" "<<y<<endl;
    }
    A operator +(A ob)
    {
        A get;
        get.x = x+ob.x;
        get.y = y+ob.y;
        return get;
    }
};

int main()
{
    A a1(4,6),a2(6,2),a3;
    a3 = a1+a2;
    a1.display();
    a2.display();
    a3.display();
}
