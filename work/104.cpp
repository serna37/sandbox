#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    if (N & 1) {
        int md = N / 2;
        ans = B[md] - A[md] + 1;
    } else {
        ans = B[N / 2 - 1] + B[N / 2] - A[N / 2 - 1] - A[N / 2] + 1;
    }
    cout << ans << endl;
}
