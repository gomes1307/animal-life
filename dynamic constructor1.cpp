#include<iostream>
using namespace std;
class A
{
public:
    int *ptr;
    A(int size)
    {
        ptr=new int[size];
        cout<<"Dynamic construtor was called eith size: "<<size<<endl;
    }
    ~A()
    {
        delete[]ptr;
        cout<<"Destructor was called"<<endl;
    }
};
int main()
{
    A ob(1);
    ob.ptr[0]=1;
    cout<<"ob.ptr[0] = " << ob.ptr[0] << endl;

}
