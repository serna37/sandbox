#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> c(9);
    for (int i = 0; i < 9; i++) {
        cin >> c[i];
    }
    vector<int> p(9);
    iota(p.begin(), p.end(), 0);
    int cnt = 0, all = 0;
    do {
        all++;
        bool ok = true;
        auto f = [&](int i, int j, int k) {
            vector<pair<int, int>> d;
            d.push_back({p[i], c[i]});
            d.push_back({p[i], c[i]});
            d.push_back({p[i], c[i]});
        };
        if (ok) {
            cnt++;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << (double)cnt / all << endl;
}
