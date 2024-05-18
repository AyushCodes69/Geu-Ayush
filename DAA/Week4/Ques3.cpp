#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex > k - 1) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k;

        if (k > 0 && k <= n) {
            int kthSmallest = quickSelect(arr, 0, n - 1, k);
            if (kthSmallest != -1) {
                cout << kthSmallest << endl;
            } else {
                cout << "not present" << endl;
            }
        } else {
            cout << "Invalid value of k" << endl;
        }
    }

    return 0;
}
