#include <bits/stdc++.h>
using namespace std;
int main() {
    auto p_fact = []<class T>(T N) -> map<T, int> {
        map<T, int> P;
        for (T i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                P[i]++;
                N /= i;
            }
        }
        if (N > 1) {
            P[N]++;
        }
        return P;
    };
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << (p_fact(N).size() >= 2 ? "Yes" : "No") << endl;
    }
}
