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
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            a[i] = Q[i] / A[i];
        } else {
            a[i] = INF;
        }
        if (B[i] != 0) {
            b[i] = Q[i] / B[i];
        } else {
            b[i] = INF;
        }
    }
    int ma = *min_element(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i <= ma; i++) {
        int mnb = INF;
        bool ng = false;
        for (int j = 0; j < N; j++) {
            if (B[j] == 0) {
                continue;
            }
            int zan = Q[j] - A[j] * i;
            if (zan >= B[j]) {
                mnb = min(mnb, zan / B[j]);
            } else {
                ng = true;
                break;
            }
        }
        if (!ng) {
            ans = max(ans, mnb + i);
        } else {
            ans = max(ans, i);
        }
    }
    int mb = *min_element(b.begin(), b.end());
    for (int i = 1; i <= mb; i++) {
        int mnb = INF;
        bool ng = false;
        for (int j = 0; j < N; j++) {
            if (A[j] == 0) {
                continue;
            }
            int zan = Q[j] - B[j] * i;
            if (zan >= A[j]) {
                mnb = min(mnb, zan / A[j]);
            } else {
                ng = true;
                break;
            }
        }
        if (!ng) {
            ans = max(ans, mnb + i);
        } else {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
}
