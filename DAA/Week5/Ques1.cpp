#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findMaxOccurrence(vector<char>& arr) {
    unordered_map<char, int> count;

    for (char c : arr) {
        count[c]++;
    }

    char maxChar = arr[0];
    int maxCount = count[arr[0]];

    for (char c : arr) {
        if (count[c] > maxCount) {
            maxChar = c;
            maxCount = count[c];
        }
    }

    if (maxCount == 1) {
        cout << "No Duplicates Present\n";
    } else {
        cout << maxChar << " - " << maxCount << "\n";
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<char> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        findMaxOccurrence(arr);
    }

    return 0;
}
