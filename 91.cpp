#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long p = 0;
    long long s = 0;
    for (int i = 0; i < N; i++) {
        p += (long long)A[i] * A[i] * (N - 1);
        s += A[i];
    }
    long long m = 0;
    for (int i = 0; i < N; i++) {
        m += A[i] * (s - A[i]);
    }
    cout << p - m << endl;
}
