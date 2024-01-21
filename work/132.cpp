#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<long long> Z(N + 1);
    for (int i = 0; i < N; i++) {
        Z[i + 1] = Z[i] + a[i];
    }
    long long ans = 0;
    for (int i = 0; i < N + 1; i++) {
        auto itr = lower_bound(Z.begin(), Z.end(), Z[i] + K);
        if (itr == Z.end()) {
            continue;
        }
        ans += Z.end() - itr;
    }
    cout << ans << endl;
}
