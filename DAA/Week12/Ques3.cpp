#include <iostream>
#include <algorithm>
using namespace std;
void printPermutations(string str) {
    sort(str.begin(), str.end());
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "All permutations in lexicographic order are: " << endl;
    printPermutations(input);
    return 0;
}

