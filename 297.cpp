#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<int> mst = p;
    sort(mst.begin(), mst.end());
    if (p == mst) {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(p[i], p[j]);
            if (p == mst) {
                cout << "YES" << endl;
                return 0;
            }
            swap(p[i], p[j]);
        }
    }
    cout << "NO" << endl;
}
