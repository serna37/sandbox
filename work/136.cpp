#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(), S.end());
    long long M = powl(10, N);
    long long ans = 0;
    for (long long i = 0; i * i <= M; i++) {
        string t = to_string(i * i);
        t.resize(N, '0');
        sort(t.begin(), t.end());
        if (t == S) {
            ans++;
        }
    }
    cout << ans << endl;
}
