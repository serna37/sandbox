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
        T.push_back({A[i], B[i], 0});
    }
    for (int i = 0; i < M; i++) {
        T.push_back({C[i], D[i], 1});
    }
    sort(T.begin(), T.end());
    multiset<int> cho;
    for (int i = 0; i < N + M; i++) {
        if (get<2>(T[i]) == 0) {
            cho.insert(get<1>(T[i]));
        }
        if (get<2>(T[i]) == 1) {
            auto itr = cho.upper_bound(get<1>(T[i]));
            if (itr != cho.begin()) {
                cho.erase(--itr);
            }
        }
    }
    cout << (cho.empty() ? "Yes" : "No") << endl;
}
