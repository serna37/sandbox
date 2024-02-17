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
    if (N % 2 == 0) {
        long long am = ((long long)A[N / 2] + A[N / 2 - 1]);
        long long bm = ((long long)B[N / 2] + B[N / 2 - 1]);
        cout << bm - am + 1 << endl;
    } else {
        cout << B[N / 2] - A[N / 2] + 1 << endl;
    }
}
