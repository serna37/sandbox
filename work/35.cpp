#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> fwk(N + 1, 0);
    for (int i = 0, f = 1; i < N; i++, f++) {
        fwk[f] += A[i];
        int l = f + f & -f;
        if (l <= N) {
            fwk[l] += fwk[f];
        }
    }
    for (int f = 2; f <= N; f += f & -f) {
        fwk[f] += 4;
    }
    int ans = 0;
    for (int f = 4; f; f -= f & -f) {
        ans += fwk[f];
    }
}
