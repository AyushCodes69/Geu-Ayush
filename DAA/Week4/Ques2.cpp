#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int comparisons = 0, swaps = 0;

        srand(time(NULL));
        int randomPivot = rand() % n;

        swap(arr[randomPivot], arr[n - 1]);
        swaps++;

        quickSort(arr, 0, n - 1, comparisons, swaps);

        cout << "Sorted array:";
        printArray(arr, n);

        cout << "Comparisons = " << comparisons << endl;
        cout << "Swaps = " << swaps << endl;
    }

    return 0;
}
