#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    auto p_fact = [](int N) -> map<int, int> {
        map<int, int> P;
        for (int i = 2; i * i <= N; i++) {
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
    map<int, int> mp = p_fact(n);
    cout << n << ":";
    for (auto v : mp) {
        for (int i = 0; i < v.second; i++) {
            cout << " " << v.first;
        }
    }
    cout << endl;
}
