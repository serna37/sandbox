#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    set<int> A, B;
    for (int i = 0; i < N + 1; i++) {
        if (S[i] == 'A') {
            A.insert(i);
        } else {
            B.insert(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            if (B.empty()) {
                cout << "Alice" << endl;
                continue;
            }
            B.erase(B.begin());
        } else {
            if (A.empty()) {
                cout << "Bob" << endl;
                continue;
            }
            A.erase(A.begin());
        }
        if (A.empty()) {
            cout << "Bob" << endl;
        } else if (B.empty()) {
            cout << "Alice" << endl;
        } else if (*A.begin() < *B.begin()) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}
