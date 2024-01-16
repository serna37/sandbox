#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 4;
    long long a;
    for (int i = 0; i < N; i++) {
    }
    for (int i = N - 1; i >= 0; i--) {
    }
    vector<int> A(N);
    for (int v : A) {
    }
    auto func = [&](int a) -> void {};
    auto re = [&](auto self, int a) -> void {
        self(self, 0); // recursive;
    };
    const double PI = acos(-1);
    const int INF = 1001001001;
    const long long aINF = 1001001001001001001ll;
    const int MOD = 998244353;
    const int aMOD = 1000000007;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    vector<int> adx = {0, 1, 0, -1, 1, -1, 1, -1};
    vector<int> ady = {1, 0, -1, 0, 1, 1, -1, -1};
    cout << "snippet test" << endl;
    cout << fixed << setprecision(10);
    int ans = 0, tmp = 1;
    ans = max(ans, tmp);
    ans = min(ans, tmp);
    sort(A.begin(), A.end());
    sort(A.rbegin(), A.rend());
    // std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    auto divFloor = [](long long a, long long b) -> long long {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    };
    auto divCeil = [](long long a, long long b) -> long long {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto split = [](string s, char c) -> vector<string> {
        vector<string> S;
        string t;
        for (char v : s) {
            if (v == c) {
                if (!t.empty()) S.push_back(t);
                t.clear();
            } else {
                t += v;
            }
        }
        if (!t.empty()) S.push_back(t);
        return S;
    };
    auto digitsum = [](int a, int N = 10) -> int {
        int ans = 0;
        while (a != 0) ans += a % N, a /= N;
        return ans;
    };
    auto is_p = [](long long num) -> bool {
        if (num == 2) return true;
        if (num < 2 || num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (long long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    };
    auto p_fact = [](long long N) -> map<long long, int> {
        map<long long, int> P;
        for (long long i = 2; i * i <= N; i++) {
            while (N % i == 0) P[i]++, N /= i;
        }
        if (N > 1) P[N]++;
        return P;
    };
    auto eratosthenes = [](long long N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (long long i = 2; i * i <= N; i++) {
            if (!is_P[i]) continue;
            for (long long j = i * i; j <= N; j += i) is_P[j] = false;
        }
        return is_P;
    };
    auto modpow = [](long long a, long long n, long long mod) -> long long {
        long long res = 1;
        while (n > 0) {
            if (n & 1) res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    };
    auto modinv = [&](long long a, long long mod) -> long long {
        return modpow(a, mod - 2, mod);
    };
    auto amodinv = [](long long a, long long m) -> long long {
        long long b = m, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
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
        //
    } while (next_permutation(A.begin(), A.end()));
    for (long long bit = 0; bit < 1 << N; bit++) {
        for (int k = 0; k < N; k++) {
            if (bit & (1 << k)) {
            }
        }
    }
    ans = 0;
    int cur = 0;
    int M = 5;
    for (int i = 0; i < N; i++) {
        while (cur < N and A[cur] < A[i] + M) ++cur;
        ans = max(ans, cur - i);
    };
    queue<int> q;
    vector<vector<int>> G(N);
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        for (int v : G[a]) {
            // if (x < 0 or y < 0 or column <= x or row <= y) continue;
            q.push(v);
        }
    }
    vector<int> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        S[i] = S[i + 1] + A[i];
    }
    // A[l]++;
    // A[r + 1]--;
    // vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    // for (int i = 0; i < N; i++) {
    // int wi = weight[i];
    // int vi = value[i];
    // for (int w = 0; w <= W; ++w) {
    // if (w < wi) {
    // dp[i + 1][w] = dp[i][w];
    //} else {
    // dp[i + 1][w] = max(dp[i][w], dp[i][w - wi] + vi);
    //}
    //}
    //};
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
            seg_tree[idx] = min(seg_tree[2 * idx + 1], seg_tree[2 * idx + 2]);
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
};
