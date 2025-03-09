#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[100]={2, 4, 6};
    int size1=3;
    int arr2[100]={8, 10, 12, 14};
    int size2=4;
    int merged_size=size1+size2;
    int arr3[merged_size];
    for(int i=0;i<size1;i++)
    {
        arr3[i]=arr1[i];
        if(i==2)
        {
            for(int j=0;j<size2;j++)
            {
                i++;
                arr3[i]=arr2[j];
            }
        }
    }
    for(int i=0;i<merged_size; i++)
    {
        cout<<arr3[i]<<" ";
    }

}


