#include<iostream>
using namespace std;
int main()
{
    int arr[10],n;
    cout<<"Enter a size: ";
    cin>>n;
    cout<<"Enter element: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    n--;
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}
