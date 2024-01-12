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
    vector<tuple<int, int, int>> t;
    for (int i = 0; i < N; i++) {
        t.push_back({A[i], B[i], 1});
    }
    for (int i = 0; i < M; i++) {
        t.push_back({C[i], D[i], 2});
    }
    sort(t.begin(), t.end());
    int cnt = 0;
    multiset<int> st;
    for (int i = 0; i < N + M; i++) {
        int cate = get<2>(t[i]);
        int yoko = get<1>(t[i]);
        if (cate == 1) {
            st.insert(yoko);
            continue;
        }
        auto itr = st.upper_bound(yoko);
        if (itr == st.begin()) {
            continue;
        }
        st.erase(--itr);
        cnt++;
    }
    if (cnt == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
