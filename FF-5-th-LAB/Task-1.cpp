#include <iostream>
using namespace std;
int Merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left, invCount = 0;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            invCount += (n1 - i);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    return invCount;
}
int mergeAndCount(int arr[], int left, int right)
{
    if (left >= right)
    {
        return 0;
    }
    int mid = left + (right - left) / 2;
    int invCount = 0;
    invCount += mergeAndCount(arr, left, mid);
    invCount += mergeAndCount(arr, mid + 1, right);
    invCount += Merge(arr, left, mid, right);
    return invCount;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        cout<< mergeAndCount(arr,0,n-1)<<endl;
    }
}

