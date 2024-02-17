#include <bits/stdc++.h>
using namespace std;
template <typename T> struct FwkTree {
  private:
    int e = 0;
    int N;
    vector<T> node;
    void bind(T &a, T b) {
        a += b;
    }

  public:
    FwkTree(int n) : N(n), node(n + 1, e){};
    void build(vector<T> a) {
        for (int i = 1; i <= N; i++) {
            bind(node[i], a[i - 1]);
            int f = i + (i & -i);
            if (f <= N) {
                bind(node[f], node[i]);
            }
        }
    }
    void act(int i, T x) {
        for (int f = i + 1; f <= N; f += f & -f) {
            bind(node[f], x);
        }
    }
    T fold(int r) {
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
    vector<int> A(n, 0);
    fwk.build(A);
    while (q--) {
        int com, x, y;
        cin >> com >> x >> y;
        x--;
        if (com == 0) {
            fwk.act(x, y);
        } else {
            cout << fwk.fold(y - 1) - fwk.fold(x - 1) << endl;
        }
    }
}
