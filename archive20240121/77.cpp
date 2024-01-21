#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> mst = a;
    sort(mst.begin(), mst.end());
    vector<vector<int>> D(K);
    for (int i = 0; i < N; i++) {
        D[i % K].push_back(a[i]);
    }
    vector<int> ans;
    for (auto &v : D) {
        sort(v.begin(), v.end());
    }
    for (int i = 0; i < N; i++) {
        ans.push_back(D[i % K][i / K]);
    }
    if (ans == mst) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
