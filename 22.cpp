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
    }
    vector<int> s(N);
    s[0] = A[0];
    for (int i = 1; i < N; i++) {
        s[i] = s[i - 1] + A[i];
    }
    for (int i = 0; i < N; i++) {
        cout << (s[i] & 1);
    }
    cout << endl;
}
