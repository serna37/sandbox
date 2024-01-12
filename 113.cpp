#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N), C(M), D(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> D[i];
    }
    vector<tuple<int, int, int>> T;
    for (int i = 0; i < N; i++) {
        T.push_back({A[i], B[i], 0});
    }
    for (int i = 0; i < M; i++) {
        T.push_back({C[i], D[i], 1});
    }
    sort(T.begin(), T.end());
    int ans = 0;
    multiset<int> st;
    for (int i = 0; i < N + M; i++) {
        int category = get<2>(T[i]);
        int yoko = get<1>(T[i]);
        if (category == 0) {
            st.insert(yoko);
            continue;
        }
        auto itr = st.upper_bound(yoko);
        if (itr == st.begin()) {
            continue;
        }
        st.erase(--itr);
        ans++;
    }
    if (ans == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
