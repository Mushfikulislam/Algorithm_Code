#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010];

void dfs(int l, int r)
{
    if (k == 1 || l + 1 == r)
    {
        return;
    }
    k -= 2;
    int mid = (l + r)/2;
    swap(a[mid], a[mid - 1]);
    dfs(l, mid);
    dfs(mid, r);
}

int main()
{
    cin >> n >> k;
    if (k % 2 == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    dfs(0, n);
    if (k != 1)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }
}
