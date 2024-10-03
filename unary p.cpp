#include<iostream>
using namespace std;
class Space
{
    int x,y,z;
public :
    void getdata(int a,int b,int c)
    {
        x = a;
        y = b;
        z = c;
    }
    void display()
    {
        cout<<x<<" "<<y<<" "<<z<<" "<<endl;
    }
    void operator-()
    {
    x =  x;
    y = -y;
    z = -z;
    }
};

int main()
{
 Space s;
 s.getdata(5,-10,15);
 s.display();
 -s;
 s.display();
return 0;
}
