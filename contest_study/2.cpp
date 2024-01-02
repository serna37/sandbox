#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = N; i < 919; i++) {
        int a = i / 100;
        int b = (i % 100) / 10;
        int c = i % 10;
        if (a * b == c) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
