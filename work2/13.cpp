#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    set<pair<int, int>> st;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (abs(A[i] - B[i]) == 0) {
            continue;
        }
        if (A[i] == 1 and B[i] == 2 * N) {
            continue;
        }
        if (B[i] == 1 and A[i] == 2 * N) {
            continue;
        }
        if (A[i] < B[i]) {
            st.insert({A[i], B[i]});
        } else {
            st.insert({B[i], A[i]});
        }
    }
    vector<int> left, right;
    set<int> ss;
    for (auto v : st) {
        left.push_back(v.first);
        right.push_back(v.second);
        ss.insert(v.first);
        auto itr = ss.upper_bound(v.first);
        if (itr != ss.end() and *itr < v.second) {
            cout << "Yes" << endl;
            return 0;
        }
        ss.insert(v.second);
    }
    cout << "No" << endl;
}
