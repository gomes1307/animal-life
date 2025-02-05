#include<iostream>
using namespace std;
int main()
{
    int arr[10];
    int siz,val,i;
    cin>>siz>>val;
    for(i=0;i<siz;i++)
    {
        cin>>arr[i];
    }
    arr[i]=val;
    siz++;
    for(i=0;i<siz;i++)
    {
        cout<<arr[i]<<" ";
    }
}
