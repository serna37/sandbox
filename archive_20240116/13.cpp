#include <bits/stdc++.h>
using namespace std;
int main() {
    int D, N;
    cin >> D >> N;
    int d = powl(100, D);
    int c = 0;
    for (int i = 1; i <= 150; i++) {
        int t = d * i;
        int cnt = 0;
        while (t % 100 == 0) {
            cnt++;
            t /= 100;
        }
        if (cnt == D) {
            c++;
        }
        if (c == N) {
            cout << d * i << endl;
            return 0;
        }
    }
}
