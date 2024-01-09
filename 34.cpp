#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(K);
    vector<vector<int>> b(K);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i % K].push_back(a[i]);
    }
    for (int i = 0; i < K; i++) {
        sort(b.rbegin(), b.rend());
    }
    vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans.push_back(b[i % K].back());
        b[i % K].pop_back();
    }
    sort(a.begin(), a.end());
    if (a == ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
