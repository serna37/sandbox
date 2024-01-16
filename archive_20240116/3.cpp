#include <bits/stdc++.h>
using namespace std;
int main() {
    int m;
    cin >> m;
    vector<pair<int, int>> t(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        t[i] = {x, y};
    }
    int n;
    cin >> n;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }
    for (pair<int, int> ss : s) {
        pair<int, int> diff;
        for (int i = 0; i < m; i++) {
            diff = {ss.first - t[i].first, ss.second - t[i].second};
            bool allma = true;
            for (int o = 0; o < m; o++) {
                pair<int, int> want = {t[o].first + diff.first,
                                       t[o].second + diff.second};
                allma &= s.find(want) != s.end();
            }
            if (allma) {
                cout << diff.first << " " << diff.second << endl;
                return 0;
            }
        }
    }
};
