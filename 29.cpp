#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int canuse = 0;
    int ans = INF;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        canuse += A[i] / X;
        sum += A[i];
    }
    if (canuse <= K) {
        cout << sum - (K * X) << endl;
    } else {
        K -= canuse;
        for (int i = 0; i < N; i++) {
            A[i] %= X;
        }
        sort(A.rbegin(), A.rend());
        for (int i = 0; i < min(N, K); i++) {
            A[i] = 0;
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += A[i];
        }
        cout << ans << endl;
    }
}
