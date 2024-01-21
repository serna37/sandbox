#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    vector<pair<int, int>> p;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        p.push_back({a[i], b[i]});
    }
    sort(p.begin(), p.end());
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += p[i].second;
    }
    if (sum <= K) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if (sum <= K) {
            cout << p[i - 1].first + 1 << endl;
            return 0;
        }
        sum -= p[i].second;
    }
    cout << p.back().first + 1 << endl;
}
