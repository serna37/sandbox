#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<set<int>> B(N);
    for (int i = 0; i < N; i++) {
        B[i].insert(C[i]);
    }
    while (Q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (B[a].size() > B[b].size()) {
            swap(B[a], B[b]);
        }
        for (auto v : B[a]) {
            B[b].insert(v);
        }
        B[a].clear();
        cout << B[b].size() << endl;
    }
}
