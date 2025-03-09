#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,M=100;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        for(int i=0; i<n; i++)
        {
            if(M>arr[i])
            {
                M=arr[i];
            }
        }
        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > M)
            {
                operations++;
            }
        }
        cout << operations << endl;
    }
}

