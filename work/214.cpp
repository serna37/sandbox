#include <bits/stdc++.h>
using namespace std;
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename M> struct FwkTree {
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    T total;
    void bind(T &x, const T &y) {
        x = M::op(x, y);
    }

  public:
    FwkTree(int n) : N(n), node(n + 1, M::e), total(M::e){};
    FwkTree(int n, const vector<T> &a) : N(n), node(n + 1, M::e), total(M::e) {
        for (int i = 1; i <= N; i++) {
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(const int &i, const T &x) {
        total += x;
        for (int f = i + 1; f <= N; f += f & -f) bind(node[f], x);
    }
    T get(const int &r) {
        T ans = M::e;
        for (int f = r + 1; f; f -= f & -f) bind(ans, node[f]);
        return ans;
    }
    T top() {
        return total;
    }
    void debug() {
        cout << "Fenwick";
        for (auto &v : node) {
            cout << " " << v;
        }
        cout << endl;
    }
};
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> cvt = A;
    sort(cvt.begin(), cvt.end());
    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());
    for (auto &v : A) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    int cnt = cvt.size();
    // cout << "Fenwick build:size:" << cnt << endl;
    // cout << "debug_A:";                // TODO debug
    // for (auto v : A) cout << " " << v; // TODO debug
    // cout << endl;                      // TODO debug
    FwkTree<Madd<int>> fwk(cnt);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        // fwk.debug();
        // cout << "get:" << A[i] << ":" << fwk.get(A[i]) << endl;
        // cout << "top:" << fwk.top() << endl;
        ans += fwk.top() - fwk.get(A[i]);
        // cout << ans << endl;
        fwk.act(A[i], 1);
    }
    // cout << "then" << endl;
    // cout << ans << endl;
    // cout << "=======" << endl;
    long long tmp = 0;
    for (int i = 0; i < N; i++) {
        // cout << A[i] << endl;
        // cout << fwk.top() << endl;
        // cout << fwk.get(A[i]) << endl;
        // cout << "==" << endl;
        tmp += fwk.top() - fwk.get(A[i]);
        fwk.act(A[i], 1);
    }
    // cout << tmp << endl;
    // return 0;
    tmp -= ans;
    // long long t = 0;
    // for (int i = 0; i < N; i++) {
    // for (int j = 0; j < N; j++) {
    // if (A[i] > A[j]) {
    // t++;
    //}
    //}
    //} // cout << ans << endl;
    // cout << tmp << endl;
    const long long MOD = 1000000007;
    ans *= K;
    ans %= MOD;
    tmp *= K * (K - 1) / 2 % MOD;
    ans += tmp;
    ans %= MOD;
    cout << ans << endl;
}
