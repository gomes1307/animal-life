#include<iostream>
using namespace std;
int main()
{
    int x;
    cout<<"enter any integer : ";
    cin>>x;

    if(x>0)
        cout<<"positive";
    if(x<0)
        cout<<"negative";
    if(x==0)
        cout<<"zero";
}
