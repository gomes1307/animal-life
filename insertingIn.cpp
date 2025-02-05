#include<iostream>
using namespace std;
int main()
{
    int arr[5] ={1,2,3,4,5};
    int siz ,val;
    cin>>siz>>val;
    for(int i=siz;i>1;i--)
    {
        arr[i-1]=arr[i-2];
    }
    siz++;
    arr[0]= val;
    for(int i=0;i<siz;i++)
    {
        cout<<arr[i]<<" ";
    }
}
