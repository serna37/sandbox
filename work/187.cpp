#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    vector<int> C(M);
    for (int i = 0; i < M; i++) {
        cin >> C[i];
    }
    vector<int> D(M);
    for (int i = 0; i < M; i++) {
        cin >> D[i];
    }
    vector<tuple<int, int, int>> T;
    for (int i = 0; i < N; i++) {
        T.push_back({A[i], B[i], 1});
    }
    for (int i = 0; i < M; i++) {
        T.push_back({C[i], D[i], 2});
    }
    sort(T.begin(), T.end());
    multiset<int> st;
    for (int i = 0; i < N + M; i++) {
        if (get<2>(T[i]) == 1)
            st.insert(get<1>(T[i]));
        else {
            auto itr = st.upper_bound(get<2>(T[i]));
            if (itr != st.begin()) {
                st.erase(--itr);
            }
        }
    }
    cout << (st.size() == 0 ? "Yes" : "No") << endl;
}
