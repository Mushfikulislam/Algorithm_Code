#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Square Matrix length n*n: ";
    cin>>n;
    int A[n][n],B[n][n],C[n][n];
    int i=0, j=0, k=0;
    cout<<"Enter The Matrix A:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    cout<<"Enter The Matrix B:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>B[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j]=0;
            for(k=0;k<n;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    cout<<"The result matrix  C:"<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}
