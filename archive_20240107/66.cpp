#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if (i + 1 != p) {
            cnt++;
        }
    }
    if (cnt == 0 or cnt == 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
