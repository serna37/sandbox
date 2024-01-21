#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        A[l]++;
        A[r]--;
    }
    vector<int> Z(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + A[i];
    }
    for (int i = 1; i < N + 1; i++) {
        if (Z[i] & 1) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}
