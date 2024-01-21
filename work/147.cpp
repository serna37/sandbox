#include <bits/stdc++.h>
using namespace std;
int main() {
    int N = 5;
    vector<int> fwk(N + 1, 0);
    int ans = 0;
    for (int f = 4; f <= N; f -= f & -f) {
        ans += fwk[f];
    }
    for (int f = 3; f <= N; f += f & -f) {
        fwk[f]++;
    }
}
