#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<long long> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    vector<long long> s = {0};
    partial_sum(A.begin(), A.end(), back_inserter(s));
    vector<int> AA = {0};
    partial_sum(A.begin(), A.end(), back_inserter(AA));
}
