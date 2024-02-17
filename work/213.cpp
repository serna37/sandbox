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
    void bind(T &x, const T &y) {
        x = M::op(x, y);
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
    T top() {
        return node[N];
    }
};
int main() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> s(N);
    for (int i = 0; i < N; i++) {
        s[i] = S[i] == 'W' ? 0 : 1;
    }
    FwkTree<Madd<int>> fwk(2);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += fwk.top() - fwk.get(s[i]);
        fwk.act(s[i], 1);
    }
    cout << ans << endl;
}
