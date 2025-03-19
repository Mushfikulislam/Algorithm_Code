#include <iostream>
using namespace std;

int countAndMerge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }

    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            res += (n1 - i);
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    return res;
}
int countInv(int arr[], int l, int r) {
    int res = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        res = res + countInv(arr, l, m);
        res = res + countInv(arr, m + 1, r);
        res = res + countAndMerge(arr, l, m, r);
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    cout << "Number of inversions are: " << countInv(arr, 0, n - 1) << endl;

    return 0;
}
