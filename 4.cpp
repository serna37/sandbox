#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        m[i] = i;
    }
    double dist = 0;
    int cnt = 0;
    do {
        for (int i = 0; i < N - 1; i++) {
            dist += hypot(x[m[i + 1]] - x[m[i]], y[m[i + 1]] - y[m[i]]);
        }
        cnt++;
    } while (next_permutation(m.begin(), m.end()));
    cout << fixed << setprecision(10);
    cout << dist / cnt << endl;
}
