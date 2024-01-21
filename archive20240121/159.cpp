#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    long long sum = 0, sq = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        sq += (long long)(N - 1) * A[i] * A[i];
    }
    for (int i = 0; i < N; i++) {
        sq -= (long long)(sum - A[i]) * A[i];
    }
    cout << sq << endl;
}
