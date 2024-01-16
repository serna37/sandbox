#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> B;
    B.push_back(0);
    for (int i = 0; i < M; i++) {
        B.push_back(A[i]);
    }
    B.push_back(N + 1);
    int m = B.size();
    vector<int> D;
    for (int i = 0; i < m - 1; i++) {
        int d = B[i + 1] - B[i] - 1;
        if (d != 0) {
            D.push_back(d);
        }
    }
    if (D.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int k = *min_element(D.begin(), D.end());
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    int ans = 0;
    for (auto v : D) {
        ans += divCeil(v, k);
    }
    cout << ans << endl;
}
