#include <iostream>
using namespace std;

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;

    cout << "Common Elements: ";
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m;
    int arr1[m];
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cin >> n;
    int arr2[n];
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    findCommonElements(arr1, m, arr2, n);

    return 0;
}
