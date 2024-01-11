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
    vector<int> a;
    a.push_back(0);
    for (int i = 0; i < M; i++) {
        a.push_back(A[i]);
    }
    a.push_back(N + 1);
    int ss = a.size();
    vector<int> K;
    for (int i = 0; i < ss; i++) {
        int tmp = a[i + 1] - a[i] - 1;
        if (tmp > 0) {
            K.push_back(tmp);
        }
    }
    if (K.empty()) {
        cout << 0 << endl;
        return 0;
    }
    int k = *min_element(K.begin(), K.end());
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    long long ans = 0;
    for (auto v : K) {
        ans += divCeil(v, k);
    }
    cout << ans << endl;
}
