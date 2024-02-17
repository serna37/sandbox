#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<pair<int, int>> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] == 1 and B[i] == 2 * N) {
        } else if (B[i] == 1 and A[i] == 2 * N) {
        } else if (abs(A[i] - B[i]) == 1) {
        } else {
            if (A[i] > B[i]) {
                swap(A[i], B[i]);
            }
            mp.push_back({A[i], B[i]});
        }
    }
    sort(mp.begin(), mp.end());
    set<int> st;
    for (auto &v : mp) {
        st.insert(v.first);
        st.insert(v.second);
        auto itr = st.upper_bound(v.first);
        if (*itr != v.second) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
