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
template <class M> struct testtest {};
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i] - K;
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
