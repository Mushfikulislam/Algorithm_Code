#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"INPUT:" <<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum=sum+arr[i];
    }
    cout<<"Output: "<<endl;
    cout<<sum;
    return 0;

}
