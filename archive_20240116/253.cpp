#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    vector<set<int>> st;
    for (int i = 0; i < N; i++) {
        st.push_back({C[i]});
    }
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (st[a].size() > st[b].size()) {
            swap(st[a], st[b]);
        }
        for (auto v : st[a]) {
            st[b].insert(v);
        }
        st[a].clear();
        cout << st[b].size() << endl;
    }
}
