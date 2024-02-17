#include <bits/stdc++.h>
using namespace std;
template <class M> struct SegTree {
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    void update(const int &i) {
        node[i] = M::ope(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n) : N(n), node(n << 1, M::e){};
    SegTree(int n, const vector<T> &a) : N(n), node(n << 1, M::e) {
        for (int i = 0; i < N; i++) node[i + N] = a[i];
        for (int i = N - 1; i >= 0; i--) update(i);
    }
    T operator[](const int &i) {
        return node[i + N];
    }
    void set(int i, const T &x) {
        node[i += N] = x;
        while (i >>= 1) update(i);
    }
    T get(int l, int r) {
        T L = M::e, R = M::e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = M::ope(L, node[l++]);
            if (r & 1) R = M::ope(node[--r], R);
        }
        return M::ope(L, R);
    }
    T top() {
        return node[1];
    }
};
template <typename T> struct RxQsum {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T ope(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename M> struct FwkTree {
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    void bind(T &x, const T &y) {
        x = M::ope(x, y);
    }

  public:
    FwkTree(int n) : N(n), node(n + 1, M::e){};
    FwkTree(int n, const vector<T> &a) : N(n), node(n + 1, M::e) {
        for (int i = 1; i <= N; i++) {
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(const int &i, const T &x) {
        for (int f = i + 1; f <= N; f += f & -f) bind(node[f], x);
    }
    T get(const int &r) {
        T ans = M::e;
        for (int f = r + 1; f; f -= f & -f) bind(ans, node[f]);
        return ans;
    }
};
int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        S[i + 1] = S[i] + A - K;
    }
    vector<long long> cvt = S;
    sort(cvt.begin(), cvt.end());
    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());
    for (auto &v : S) v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    int cnt = cvt.size();
    long long ans = 0;
    FwkTree<RxQsum<int>> fwk(cnt);
    for (int i = 0; i < N + 1; i++) {
        ans += fwk.get(S[i]);
        fwk.act(S[i], 1);
    }
    cout << ans << endl;
}
