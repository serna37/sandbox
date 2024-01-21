#include <bits/stdc++.h>
using namespace std;
int main() {
    int D, N;
    cin >> D >> N;
    int atom = pow(100, D);
    int cnt = 0;
    for (int i = 1; i < N * 2; i++) {
        int tmp = atom * i;
        int c = 0;
        while (tmp % 100 == 0) {
            c++;
            tmp /= 100;
        }
        if (c == D) {
            cnt++;
        }
        if (cnt == N) {
            cout << atom * i << endl;
            return 0;
        }
    }
}
