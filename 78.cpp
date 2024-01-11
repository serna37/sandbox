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
    vector<int> D;
    D.push_back(0);
    for (int i = 0; i < M; i++) {
        D.push_back(A[i]);
    }
    D.push_back(N + 1);
    int ds = D.size();
    vector<int> diff;
    for (int i = 0; i < ds; i++) {
        int d = D[i + 1] - D[i] - 1;
        if (d > 0) {
            diff.push_back(d);
        }
    }
    if (diff.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int k = *min_element(diff.begin(), diff.end());
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    int ans = 0;
    for (auto v : diff) {
        ans += divCeil(v, k);
    }
    cout << ans << endl;
}
