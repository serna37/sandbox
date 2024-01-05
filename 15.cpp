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
        A[l] += 1;
        A[r + 1] -= 1;
    }
    vector<int> sum(N);
    sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + A[i];
    }
    for (int i = 0; i < N; i++) {
        cout << (sum[i] & 1);
    }
    cout << endl;
}
