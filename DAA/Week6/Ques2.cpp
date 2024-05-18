#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void findTwoElements(vector<int> arr, int key) {
    quicksort(arr, 0, arr.size() - 1);

    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == key) {
            cout << arr[left] << " " << arr[right] << endl;
            return;
        } else if (sum < key) {
            left++;
        } else {
            right--;
        }
    }
    cout << "No Such Elements Exist" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, key;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> key;
        findTwoElements(arr, key);
    }
    return 0;
}
