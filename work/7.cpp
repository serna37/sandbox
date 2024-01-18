#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<vector<int>> a(N);
    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        a[i].resize(L);
        for (int j = 0; j < L; j++) {
            cin >> a[i][j];
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size() << endl;
}
