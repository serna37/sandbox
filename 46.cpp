#include <bits/stdc++.h>
using namespace std;
int main() {
    auto eratosthenes = [](int N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (!is_P[i]) continue;
            for (int j = i * i; j <= N; j += i) is_P[j] = false;
        }
        return is_P;
    };
    vector<bool> era = eratosthenes(1e5);
    vector<int> P(1e5);
    for (int i = 1; i < 1e5; i += 2) {
        if (era[i] and era[(i + 1) / 2]) {
            P[i]++;
        }
    }
    vector<int> S(1e5 + 1);
    for (int i = 0; i < 1e5; i++) {
        S[i + 1] = S[i] + P[i];
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << S[r + 1] - S[l] << endl;
    }
}
