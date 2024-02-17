#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S = to_string(N);
    sort(S.begin(), S.end());
    int M = S.size();
    long long ans = 0;
    do {
        for (int i = 1; i < M; i++) {
            string pre = S.substr(0, i);
            string post = S.substr(i, M);
            int p1 = stoi(pre);
            int p2 = stoi(post);
            if (p1 == 0 or p2 == 0) {
                continue;
            }
            ans = max(ans, (long long)p1 * p2);
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << ans << endl;
}
