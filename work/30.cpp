#include <bits/stdc++.h>
using namespace std;
int main() {
    long long A, B;
    cin >> A >> B;
    long long g = gcd(A, B);
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
    auto a = p_fact(g);
    cout << a.size() + 1 << endl;
}
