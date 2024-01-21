#include <bits/stdc++.h>
using namespace std;
int main() {
    int atom = INF;
    vector<int> seg(N << 1, atom);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        seg[i + N] = A;
    }
    for (int i = N - 1; i >= 0; i--) {
        bind
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    dp[0][0] = ;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
        }
    }
    cout << dp[N][M] << endl;
    vector<bool> vis(N);
    queue<int> q;
    q.push(initial q);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (vis[v]) {
            continue;
        }
        vis[v] = true;
        for (int n : G[v]) {
            q.push(n);
        }
    }
    auto comp = []<class T>(vector<T> vec) -> vector<T> {
        auto v = vec;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        }
        return vec;
    };
    vector<int> Z(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + A[i];
    }
    vector<vector<int>> Z(H + 1, vector<int>(W + 1));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Z[i + 1][j + 1] = Z[i + 1][j] + A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            Z[i + 1][j + 1] += Z[i][j + 1];
        }
    }
    auto eratosthenes = []<class T>(T N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (T i = 2; i * i <= N; i++) {
            if (!is_P[i]) {
                continue;
            }
            for (T j = i * i; j <= N; j += i) {
                is_P[j] = false;
            }
        }
        return is_P;
    };
    auto modinv_fermat = [&](long long a) -> long long {
        return mod_pow(a, MOD - 2);
    };
    const int MAX = 3e5;
    long long fac[MAX], finv[MAX], inv[MAX];
    auto Extended_Euclid_inverse_calc = [&]() -> void {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    };
    Extended_Euclid_inverse_calc();
    auto nCk = [&](int n, int k) -> long long {
        if (n < k or n < 0 or k < 0) {
            return 0;
        }
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    };
}
