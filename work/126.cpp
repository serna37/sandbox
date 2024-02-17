#include <bits/stdc++.h>
using namespace std;
template <typename T> struct SegTree {
  private:
    int e = 0;
    int N;
    vector<T> node;
    T bind(const T &a, const T &b) {
        return a + b;
    }

  public:
    SegTree(int n) : N(n), node(n << 1, e){};
    T operator[](const int &i) {
        return node[i + N];
    }
    void build(const vector<T> &a) {
        for (int i = 0; i < N; i++) {
            node[i + N] = a[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            node[i] = bind(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    void set(int i, const T &x) {
        node[i += N] = x;
        while (i >>= 1) {
            node[i] = bind(node[i << 1 | 0], node[i << 1 | 1]);
        }
    }
    T get(int l, int r) {
        T vl = e, vr = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                vl = bind(vl, node[l++]);
            }
            if (r & 1) {
                vr = bind(node[--r], vr);
            }
        }
        return bind(vl, vr);
    }
    T top() {
        return node[1];
    }
};
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i] - K;
    }
    vector<long long> cvt = S;
    sort(cvt.begin(), cvt.end());
    cvt.erase(unique(cvt.begin(), cvt.end()), cvt.end());
    for (auto &v : S) {
        v = lower_bound(cvt.begin(), cvt.end(), v) - cvt.begin();
    }
    int cnt = cvt.size();
    long long ans = 0;
    SegTree<int> seg(cnt);
    for (int i = 0; i < N + 1; i++) {
        ans += seg.get(0, S[i] + 1);
        seg.set(S[i], seg[S[i]] + 1);
    }
    cout << ans << endl;
}
