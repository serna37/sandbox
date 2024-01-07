#include <bits/stdc++.h>
using namespace std;
int main() {
    auto eratosthenes = [](int N) -> vector<int> {
        vector<int> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (!is_P[i]) continue;
            for (int j = i * i; j <= N; j += i) is_P[j] = false;
        }
        return is_P;
    };
    vector<int> a = eratosthenes(10);
    for (int &v : a) {
        cout << v << endl;
    }
    int N = 10;
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> L(N + 1), R(N + 1);
    for (int i = 0; i < N; i++) {
        L[i + 1] = L[i] + A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        R[i] = R[i + 1] + A[i];
    }
    for (int i = 0; i < N + 1; i++) {
        cout << L[i] << " : " << R[i] << endl;
    }
}
