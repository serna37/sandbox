#include <bits/stdc++.h>
using namespace std;
int main() {
    auto is_prime = [](int num) -> bool {
        if (num == 2) return true;
        if (num < 2 || num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    };
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> L[i] >> R[i];
    }
    for (int i = 0; i < Q; i++) {
        int l = L[i], r = R[i];
        int ans = 0;
        for (int k = l; k <= r; k++) {
            if (is_prime(k) and is_prime((k + 1) / 2)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
