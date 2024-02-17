#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        mp[A]++;
    }
    vector<int> A;
    for (auto &v : mp) {
        A.push_back(v.second);
    }
    int M = A.size();
    vector<long long> S(M + 1);
    for (int i = 0; i < M; i++) {
        S[i + 1] = S[i] + A[i];
    }
    vector<long long> R(M + 1);
    for (int i = M - 1; i >= 0; i--) {
        R[i] = R[i + 1] + A[i];
    }
    long long ans = 0;
    for (int i = 1; i < M - 1; i++) {
        ans += S[i] * A[i] * R[i + 1];
    }
    cout << ans << endl;
}
