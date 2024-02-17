#include <bits/stdc++.h>
using namespace std;
template <typename T> struct FwkTree {
  private:
    int e = 0;
    int N;
    vector<T> node;
    void bind(T &a, const T &b) {
        a += b;
    }

  public:
    FwkTree(int n) : N(n), node(n + 1, e){};
    void build(const vector<T> &a) {
        for (int i = 1; i <= N; i++) {
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) {
                bind(node[f], node[i]);
            }
        }
    }
    void act(const int &i, const T &x) {
        for (int f = i + 1; f <= N; f += f & -f) {
            bind(node[f], x);
        }
    }
    T fold(const int &r) {
        T ans = e;
        for (int f = r + 1; f; f -= f & -f) {
            bind(ans, node[f]);
        }
        return ans;
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
    FwkTree<int> fwk(cnt);
    for (int i = 0; i < N + 1; i++) {
        ans += fwk.fold(S[i]);
        fwk.act(S[i], 1);
    }
    cout << ans << endl;
}
