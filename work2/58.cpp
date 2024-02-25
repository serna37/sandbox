#include <bits/stdc++.h>
using namespace std;
// idx: 自然数, val: 平方因子を除いたもの
vector<int> sqarefree(int mx = 2e5) {
    vector<int> S(mx + 1);
    for (int i = 1; i <= mx; i++) S[i] = i;
    for (int i = 2; i * i <= mx; i++) {            // 全平方数
        for (int j = i * i; j <= mx; j += i * i) { // の倍数で割りきる
            while (S[j] % (i * i) == 0) S[j] /= i * i;
        }
    }
    return S;
}
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
    }
    vector<int> sqf = sqarefree();
    map<int, int> mp;
    int zcnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            zcnt++;
            continue;
        }
        mp[sqf[A[i]]]++;
    }
    long long ans = 0;
    for (auto [num, cnt] : mp) {
        ans += nCk<long long>(cnt, 2);
    }
    ans += nCk<long long>(zcnt, 2);
    ans += (long long)zcnt * (N - zcnt);
    cout << ans << endl;
}
