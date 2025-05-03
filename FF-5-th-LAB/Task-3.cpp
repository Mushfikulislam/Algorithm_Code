#include <iostream>
#include <vector>
#include <algorithm> // For find()

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int n, x;
        cin >> n >> x;

        vector<int> arr(n);

        // Read the array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Find the index of x in the array
        int indexOfX = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                indexOfX = i;
                break;
            }
        }

        // Simulate binary search to find where x would be
        int left = 0, right = n - 1;
        int targetPosition = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == x) {
                targetPosition = mid;
                break;
            }
            if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Case 1: x is already at the correct position
        if (indexOfX == targetPosition) {
            cout << 0 << "\n";
        }
        // Case 2: One swap can place x at the right spot
        else if (arr[targetPosition] == x) {
            cout << 1 << "\n";
            cout << indexOfX + 1 << " " << targetPosition + 1 << "\n"; // +1 for 1-based index
        }
        // Case 3: Try two swaps
        else {
            bool foundTwoSwap = false;
            for (int i = 0; i < n; i++) {
                if (arr[i] == x) continue;
                swap(arr[i], arr[indexOfX]);

                // Try to do the binary search again
                int l = 0, r = n - 1;
                int newPos = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (arr[mid] == x) {
                        newPos = mid;
                        break;
                    }
                    if (arr[mid] < x) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }

                if (newPos == targetPosition) {
                    cout << 2 << "\n";
                    cout << indexOfX + 1 << " " << i + 1 << "\n";
                    cout << i + 1 << " " << targetPosition + 1 << "\n";
                    foundTwoSwap = true;
                    break;
                }

                swap(arr[i], arr[indexOfX]); // undo the swap
            }

            if (!foundTwoSwap) {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}

