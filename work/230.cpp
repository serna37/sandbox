#include <bits/stdc++.h>
using namespace std;
template <typename T> struct Madd {
    using value_type = T;
    static constexpr T e = 0;
    static constexpr T op(const T &x, const T &y) noexcept {
        return x + y;
    }
};
template <typename Monoid> struct FwkTree {
    using M = Monoid;
    using T = typename M::value_type;

  private:
    int N;
    vector<T> node;
    T tot;
    void init() {
        node.assign(N + 1, M::e);
        tot = M::e;
    }
    void bind(T &x, const T &y) {
        x = M::op(x, y);
    }

  public:
    FwkTree(int n) : N(n) {
        init();
    }
    FwkTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 1; i <= N; i++) {
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) bind(node[f], node[i]);
        }
    }
    void act(int i, const T &x) {
        tot += x;
        for (++i; i <= N; i += i & -i) bind(node[i], x);
    }
    T get(int r) {
        T ans = M::e;
        for (++r; r; r -= r & -r) bind(ans, node[r]);
        return ans;
    }
    T top() {
        return tot;
    }
};
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    FwkTree<Madd<int>> fwk(a);
    while (Q--) {
        int q, x, y;
        cin >> q >> x >> y;
        if (q == 0) {
            fwk.act(x, y);
        }
        if (q == 1) {
            cout << fwk.get(y - 1) - fwk.get(x - 1) << endl;
        }
    }
}
