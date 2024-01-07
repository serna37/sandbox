#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    cin >> S >> T;
    if (T.find(S) == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
}
