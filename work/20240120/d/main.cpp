#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;
    cin >> Q;
    int N = pow(2, 20);
    vector<long long> A(N, -1);
    set<int> st;
    for (int i = 0; i < N; i++) {
        st.insert(i);
    }
    while (Q--) {
        int t;
        long long x;
        cin >> t >> x;
        if (t == 1) {
            long long h = x;
            int id = h % N;
            auto itr = st.lower_bound(id);
            int ans = itr != st.end() ? *itr : *st.begin();
            A[ans] = x;
            st.erase(ans);
        }
        if (t == 2) {
            cout << A[x % N] << endl;
        }
    }
}
