#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        A[l]++;
        A[r + 1]--;
        vector<int> S(N + 1);
        for (int i = 0; i < N; i++) {
            S[i + 1] = S[i] + A[i];
        }
        for (int i = 1; i < N + 1; i++) {
            if (A[i] % 2 == 0) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }
}
