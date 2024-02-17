#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    vector<int> Q(N);
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
    }
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int mxQ = *max_element(Q.begin(), Q.end());
    int ans = 0;
    for (int x = 0; x <= mxQ; x++) {
        int y = INF;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (Q[i] - (long long)A[i] * x) {
                ok = false;
                break;
            }
            if (0 < B[i]) {
                y = min(y, (Q[i] - A[i] * x) / B[i]);
            }
        }
        if (ok) {
            ans = max(ans, x + y);
        }
    }
    cout << ans << endl;
}
