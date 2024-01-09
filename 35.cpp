#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a = cnt[A[i]];
        int b = cnt[A[i] - 1];
        if (A[i] == 0) {
            b = 3;
        }
        ans *= b - a;
        ans %= MOD;
        cnt[A[i]]++;
    }
    cout << ans << endl;
}
