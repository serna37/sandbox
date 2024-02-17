#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    bool alma = true;
    for (int i = 0; i < A; i++) {
        alma &= '0' <= S[i] and S[i] <= '9';
    }
    alma &= S[A] == '-';
    for (int i = A + 1; i < A + B + 1; i++) {
        alma &= '0' <= S[i] and S[i] <= '9';
    }
    cout << (alma ? "Yes" : "No") << endl;
}
