#include<iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int In_Out(int arr[],int L, int H, int Sh)
{
    int i;
    for(i=L; i<H; i++)
    {
        if(arr[i]==Sh)
            break;
    }
    if(i==(H/2))
        return 0;
    else if(i<(H/2))
    {
        return ((H/2)-i);
    }
    else if(i>(H/2))
    {
        return (i-(H/2));
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int Fn,Sh;
        cin>>Fn>>Sh;
        if(Fn==1)
        {
            int M;
            cin>>M;
            cout<<Fn<<endl;
            continue;
        }
        int arr[Fn];
        for(int i=0; i<Fn; i++)
        {
            cin>>arr[i];
        }
        arr[Fn]=Sh;
        mergeSort(arr,0,Fn);
        cout<<In_Out(arr, 0, Fn+1, Sh)<<endl;

    }
}
