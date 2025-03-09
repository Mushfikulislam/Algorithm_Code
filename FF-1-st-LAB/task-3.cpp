#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,Max=0;
        cout<<"Enter the number of mountain: ";
        cin>>n;
        int arr[n];
        cout<<"enter the highet of each mountain:"<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i]>Max)
            {
                Max=arr[i];
            }
        }
        cout<<"\nThe hight of tallest mountain is:" ;
        cout<<Max<<endl;
    }
}
