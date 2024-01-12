#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int sum = 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % N != 0) {
        cout << -1 << endl;
        return 0;
    }
    int ave = sum / N;
    for (int i = 0; i < N; i++) {
        a[i] -= ave;
    }
    int ans = N - 1;
    vector<int> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + a[i];
    }
    for (int i = 1; i < N; i++) {
        if (S[i] == 0) {
            ans--;
        }
    }
    cout << ans << endl;
}
