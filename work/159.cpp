#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <typename T> struct RxQmin {
    using value_type = T;
    static constexpr T e = inf<T>;
    static constexpr T ope(const T &x, const T &y) noexcept {
        return min(x, y);
    }
};
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
    SegTree<RxQmin<int>> seg(N << 1);
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
