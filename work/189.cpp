#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
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
                A.erase(--A.end());
            } else {
                B.erase(B.begin());
            }
        } else {
            if (A.empty()) {
                B.erase(--B.end());
            } else {
                A.erase(A.begin());
            }
        }
        int tmp =
            min(A.empty() ? INF : *A.begin(), B.empty() ? INF : *B.begin());
        if (S[tmp] == 'A') {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}
