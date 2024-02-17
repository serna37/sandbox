#include <bits/stdc++.h>
using namespace std;
template <typename T> struct FwkTree {
    int e = 0;
    int N;
    vector<T> node;
    FwkTree(int n) : N(n), node(n + 1, e){};
    void bind(T &a, T b) {
        a += b;
    }
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
    int N = 8;
    vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7};
    FwkTree<int> fwk(N);
    fwk.build(A);
    FwkTree<int> fwk2(N);
    for (int i = 0; i < N; i++) {
        fwk2.act(i, A[i]);
    }
    fwk.act(3, 8);
    cout << fwk.fold(N - 1) << endl;
    int sum = reduce(A.begin(), A.end());
    cout << sum << endl;
}
