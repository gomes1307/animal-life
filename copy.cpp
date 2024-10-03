#include<iostream>
using namespace std;
class R
{
    int W,H;
public:

    R()
    {
        W=1;
        H=2;
        cout<<"area "<<W*H<<endl;
    }
    R(int a, int b)
    {
        W=a;
        H=b;
        cout<<"area "<<W*H<<endl;
    }
     R (R&ob) {
        W = ob.W;
        H = ob.H;
        cout << "Copy constructor called" << endl;
    }
    ~R()
    {
        cout<<"Destructor is called"<<endl;
    }
};

int main()
{
    R ob;
    R ob1(5,4);
    R ob2(ob1);
}
