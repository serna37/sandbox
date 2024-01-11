#include <bits/stdc++.h>
using namespace std;
int main() {
    ans = max(ans, tmp);
    ans = min(ans, tmp);
    A.begin(), A.end();
    A.rbegin(), A.rend();
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    cout << ans << endl;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << fixed << setprecision(10);
    const double PI = acos(-1);
    const int INF = 1001001001;
    const long long INF = 1001001001001001001ll;
    const int MOD = 998244353;
    const int MOD = 1000000007;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
    vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
    auto divCeil = [](long long a, long long b) -> long long {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto divFloor = [](long long a, long long b) -> long long {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    };
    cout << "debug_A:";                // TODO debug
    for (auto v : A) cout << " " << v; // TODO debug
    cout << endl;                      // TODO debug
    auto split = [](string s, char c) -> vector<string> {
        vector<string> S;
        string t;
        for (char v : s) {
            if (v == c) {
                if (!t.empty()) {
                    S.push_back(t);
                }
                t.clear();
            } else {
                t += v;
            }
        }
        if (!t.empty()) {
            S.push_back(t);
        }
        return S;
    };
    auto p_fact = [](long long N) -> map<long long, int> {
        map<long long, int> P;
        for (long long i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                P[i]++;
                N /= i;
            }
        }
        if (N > 1) {
            P[N]++;
        }
        return P;
    };
    auto is_p = [](long long num) -> bool {
        if (num == 2) {
            return true;
        }
        if (num < 2 || num % 2 == 0) {
            return false;
        }
        double sqrtNum = sqrt(num);
        for (long long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    };
    auto eratosthenes = [](long long N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (long long i = 2; i * i <= N; i++) {
            if (!is_P[i]) {
                continue;
            }
            for (long long j = i * i; j <= N; j += i) {
                is_P[j] = false;
            }
        }
        return is_P;
    };
    auto mod_pow = [&](long long a, long long n) -> long long {
        long long res = 1;
        while (n > 0) {
            if (n & 1) {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            n >>= 1ll;
        }
        return res;
    };
    auto modinv_fermat = [&](long long a) -> long long {
        return mod_pow(a, MOD - 2);
    };
    vector<long long> mf;
    auto modfact = [&](int x) -> long long {
        if (mf.size() > x) {
            return mf[x];
        }
        if (mf.empty()) {
            mf.push_back(1);
        }
        for (int i = mf.size(); i <= x; i++) {
            long long next = mf.back() * i % MOD;
            mf.push_back(next);
        }
        return mf[x];
    };
    auto mod_combination = [&](int n, int k) -> long long {
        return modfact(n) * modinv_fermat(modfact(k)) % MOD *
               modinv_fermat(modfact(n - k)) % MOD;
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
    auto digitsum = [](int a, int N = 10) -> int {
        int ans = 0;
        while (a != 0) {
            ans += a % N;
            a /= N;
        }
        return ans;
    };
    auto comp = []<class T>(vector<T> vec) -> vector<T> {
        auto v = vec;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        }
        return vec;
    };
    do {

    } while (next_permutation(A.begin(), A.end()));
    for (int bit = 0; bit < 1 << N; bit++) {
        long long tmp = 0;
        for (int k = 0; k < N; k++) {
            if (N & (1ll << k)) {
                tmp |= A[k];
            }
        }
    }
    int ans = 0;
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N and A[r] == A[l]) {
            ++r;
        }
        ans = max(ans, r - l);
    }
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        for (int v : G[a]) {
            if (x < 0 or y < 0 or column <= x or row <= y) continue;
            q.push(v);
        }
    }
    vector<int> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    vector<int> R(N + 1);
    for (int i = N - 1; i >= 0; i--) {
        R[i] = R[i + 1] + A[i];
    }
    A[l]++;
    A[r + 1]--;
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < N; i++) {
        int wi = weight[i];
        int vi = value[i];
        for (int w = 0; w <= W; ++w) {
            if (w < wi) {
                dp[i + 1][w] = dp[i][w];
            } else {
                dp[i + 1][w] = max(dp[i][w], dp[i][w - wi] + vi);
            }
        }
    }
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < N; i++) {
        int ai = A[i];
        for (int k = 0; k <= K; ++k) {
            dp[i + 1][k] = dp[i][k];
            if (k >= ai) {
                dp[i + 1][k] = dp[i][k] or dp[i][k - ai];
            }
        }
    }
    class SegmentTreeRMQ {
        const static long long ll_MAX = (1LL << 31) - 1;
        int n_0;
        long long seg_tree[4 * 100007];

      public:
        SegmentTreeRMQ(int n) {
            n_0 = 1;
            while (n_0 < n) n_0 <<= 1;
            for (int i = 0; i < 2 * n_0; i++) {
                seg_tree[i] = ll_MAX;
            }
        }
        void update(int idx, long long val) {
            idx += n_0 - 1;
            seg_tree[idx] = val;
            while (idx > 0) {
                idx = (idx - 1) / 2;
                seg_tree[idx] =
                    min(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
            }
        }
        long long query(int l, int r) {
            int l_0 = l + n_0, r_0 = r + n_0;
            long long s = ll_MAX;
            while (l_0 < r_0) {
                if (r_0 & 1) {
                    --r_0;
                    s = min(s, seg_tree[r_0 - 1]);
                }
                if (l_0 & 1) {
                    s = min(s, seg_tree[l_0 - 1]);
                    ++l_0;
                }
                l_0 >>= 1;
                r_0 >>= 1;
            }
            return s;
        }
    }
}
