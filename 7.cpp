#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, L;
    cin >> N >> L;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a >= L) {
            ans++;
        }
    }
    cout << ans << endl;
}
