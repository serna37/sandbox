#include <bits/stdc++.h>
using namespace std;
int main() {
    auto eratosthenes = [](int N) -> vector<int> {
        vector<int> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (!is_P[i]) continue;
            for (int j = i * i; j <= N; j += i) is_P[j] = false;
        }
        return is_P;
    };
    int N = 1e5;
    vector<int> P = eratosthenes(N);
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        if (i & 1 and P[i] and P[(i + 1) / 2]) {
            cnt[i] = 1;
        }
    }
    vector<int> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + cnt[i];
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        r++;
        cout << S[r] - S[l] << endl;
    }
};
