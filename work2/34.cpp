#include <bits/stdc++.h>
using namespace std;
template <typename T> T nCk(int n, int k) {
    if (k < 0 || n < k) return 0;
    T ret = 1;
    for (T i = 1; i <= k; ++i) {
        ret *= n--;
        ret /= i;
    }
    return ret;
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<int> cnt(N), sum(N);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += (long long)(i - 1) * cnt[A[i]] - sum[A[i]];
        cnt[A[i]]++;
        sum[A[i]] += i;
    }
    for (int i = 0; i < N; i++) {
        ans -= nCk<long long>(cnt[i], 3);
    }
    cout << ans << endl;
}
