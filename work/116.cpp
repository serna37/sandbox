#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 1 << 20;
    vector<long long> A(N, -1);
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(i);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        long long x;
        cin >> t >> x;
        if (t == 1) {
            long long h = x;
            auto itr = st.lower_bound(h % N);
            int idx = itr != st.end() ? *itr : *st.begin();
            st.erase(idx);
            A[idx] = x;
        }
        if (t == 2) {
            cout << A[x % N] << endl;
        }
    }
}
