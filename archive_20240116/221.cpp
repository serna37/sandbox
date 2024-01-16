#include <bits/stdc++.h>
using namespace std;
int main() {
    int D, N;
    cin >> D >> N;
    int a = powl(100, D);
    int cnt = 0;
    for (int i = a; i < a * 200; i++) {
        int c = 0;
        int tmp = i;
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
