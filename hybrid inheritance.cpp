#include<iostream>
using namespace std;
class A
{
public:
    void display(){
        cout<<"hello"<<endl;
    }
};
class B:virtual public A
{
public:
        void display1(){
        cout<<"hi"<<endl;
    }

};
class C:virtual public A
{
public:
       void display2(){
        cout<<"go"<<endl;
    }

};
class D:public C,public B
{
public:
       void display3(){
        cout<<"now"<<endl;
    }
};

int main()
{
    D ob;
    ob.display();
    ob.display1();
    ob.display2();
    ob.display3();
}
