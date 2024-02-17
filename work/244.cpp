#include <bits/stdc++.h>
using namespace std;
template <class T> constexpr T inf = 0;
template <> constexpr int inf<int> = 1001001001;
template <> constexpr long long inf<long long> = 1001001001001001001ll;
template <class T> struct StarrySkyTree {
  private:
    int N, log, size;
    vector<T> node;
    void init() {
        log = 1;
        while ((1 << log) < N) ++log;
        size = 1 << log;
        node.assign(size << 1, -inf<T>);
    }
    T star(const int &i) {
        T mx = max(node[i << 1 | 0], node[i << 1 | 1]);
        node[i << 1 | 0] -= mx;
        node[i << 1 | 1] -= mx;
        return mx;
    }
    void act(int i, const T &x) {
        node[i] += x;
        while (i >>= 1) node[i] += star(i);
    }
    T zeta(int i) {
        T ans = node[i];
        while (i >>= 1) ans += node[i];
        return ans;
    }

  public:
    StarrySkyTree(int n) : N(n) {
        init();
    }
    StarrySkyTree(const vector<T> &a) : N(a.size()) {
        init();
        for (int i = 0; i < N; ++i) node[i + size] = a[i];
        for (int i = size - 1; i >= 1; --i) node[i] = star(i);
    }
    T operator[](int i) {
        return zeta(i + size);
    }
    T get(int l, int r) {
        T ans = -inf<T>;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, zeta(l++));
            if (r & 1) ans = max(zeta(--r), ans);
        }
        return ans;
    }
    T top() {
        return node[1];
    }
    void apply(int l, int r, T x) {
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) act(l++, x);
            if (r & 1) act(--r, x);
        }
    }
};
int main() {
    int N = 7;
    vector<int> A = {2, 4, 5, 3, 6, 7, 1};
    StarrySkyTree<int> sst1(N);
    // sst1.debug();
    StarrySkyTree<int> sst2(A);
    // sst2.debug();
    cout << sst2.top() << endl;
    // sst2.act(3, 3);
    // sst2.debug();
    // cout << sst2.top() << endl;
    cout << sst2.get(2, 7) << endl;
    sst2.apply(3, 5, 3);
    sst2.apply(0, 4, 2);
    // sst2.debug();
    cout << sst2.get(0, 8) << endl;
}
