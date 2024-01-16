#include <bits/stdc++.h>
using namespace std;
int main() {
    int D, N;
    cin >> D >> N;
    int s = powl(100, D);
    int m = s * 200;
    int cnt = 0;
    for (int i = s; i < m; i++) {
        int tmp = i;
        int c = 0;
        while (tmp % 100 == 0) {
            c++;
            tmp /= 100;
        }
        if (c == D) {
            cnt++;
        }
        if (cnt == N) {
            cout << i << endl;
            return 0;
        }
    }
}
