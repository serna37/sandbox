#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N;
    cin >> N;
    vector<int> O;
    for (int i = 0; i < 60; i++) {
        if (N & (1ll << i)) {
            O.push_back(i);
        }
    }
    int M = O.size();
    for (int bit = 0; bit < 1 << M; bit++) {
        long long tmp = 0;
        for (int k = 0; k < M; k++) {
            if (bit & (1ll << k)) {
                tmp |= (1ll << O[k]);
            }
        }
        cout << tmp << endl;
    }
}
