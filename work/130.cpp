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
    T get(const int &r) {
        T ans = e;
        for (int f = r + 1; f; f -= f & -f) {
            bind(ans, node[f]);
        }
        return ans;
    }
};
int main() {
    int n, q;
    cin >> n >> q;
    FwkTree<int> fwk(n);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        x--;
        if (com == 0) {
            fwk.act(x, y);
        } else {
            x--, y--;
            cout << fwk.get(y) - fwk.get(x) << endl;
        }
    }
}
