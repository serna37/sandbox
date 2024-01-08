#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    int ans = INF;
    for (int a = 1; a < N; a++) {
        int b = N - a;
        string as = to_string(a);
        string bs = to_string(b);
        int sum = 0;
        for (char v : as) {
            sum += v - '0';
        }
        for (char v : bs) {
            sum += v - '0';
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}
