#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(3 * N);
    for (int i = 0; i < 3 * N; i++) {
        cin >> A[i];
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < 3 * N; i++) {
        mp[A[i]].push_back(i + 1);
    }
    vector<pair<int, int>> p;
    for (auto &v : mp) {
        p.push_back({v.second[1], v.first});
    }
    sort(p.begin(), p.end());
    int M = p.size();
    for (int i = 0; i < M; i++) {
        if (i) {
            cout << " ";
        }
        cout << p[i].second;
    }
    cout << endl;
}
