#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
template <typename T> struct SegTree {
  private:
    int N;
    T e;
    vector<T> node;
    T ope(const T &a, const T &b) {
        return min(a, b);
    }
    void update(const int &i) {
        node[i] = ope(node[i << 1 | 0], node[i << 1 | 1]);
    }

  public:
    SegTree(int n, T e) : N(n), e(e), node(n << 1, e){};
    SegTree(int n, T e, const vector<T> &a) : N(n), e(e), node(n << 1, e) {
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
        T L = e, R = e;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = ope(L, node[l++]);
            if (r & 1) R = ope(node[--r], R);
        }
        return ope(L, R);
    }
    T top() {
        return node[1];
    }
};
template <typename T> struct Monoid_Min {
    using value_type = T;
    static constexpr T ope(const T &x, const T &y) noexcept {
        return min(x, y);
    }
    static constexpr T unit() {
        const int INF = 1001001001;
        return INF;
    }
};
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        if (A[i] > B[i]) {
            swap(A[i], B[i]);
        }
    }
    SegTree<int> seg(N << 1, INF);
    for (int i = 0; i < N; i++) {
        seg.set(B[i], A[i]);
    }
    for (int i = 0; i < N; i++) {
        if (seg.get(A[i] + 1, B[i]) < A[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
