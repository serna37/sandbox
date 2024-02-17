#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    map<string, pair<int, int>> mp;
    for (int i = 0; i < N; i++) {
        if (mp.count(S[i]) != 0) continue;
        mp[S[i]] = {T[i], i};
    }
    vector<pair<int, int>> p;
    for (auto &v : mp) {
        p.push_back(v.second);
    }
    sort(p.begin(), p.end());
    cout << p.back().second + 1 << endl;
}
