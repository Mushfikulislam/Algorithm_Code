#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int maxsum = INT_MIN;

        // Iterate over all possible subarrays
        for(int i = 0; i < n; i++)
        {
            int currentSum = 0;

            for(int j = i; j < n; j++)
            {
                currentSum += arr[j]; // Add current element to the sum
                if(currentSum>maxsum)
                {
                    maxsum = currentSum; // Update maxsum if the currentSum is larger
                }

            }
        }

        cout << maxsum << endl;
    }

    return 0;
}

