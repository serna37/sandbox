#include <bits/stdc++.h>
using namespace std;
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
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    FwkTree<RxQsum<long long>> fwk(N, a);
    while (Q--) {
        int q, x, y;
        cin >> q >> x >> y;
        if (q == 0) {
            fwk.act(x, y);
        } else {
            cout << fwk.get(y - 1) - fwk.get(x - 1) << endl;
        }
    }
}
