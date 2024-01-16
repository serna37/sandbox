#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    vector<int> mst(N);
    for (int i = 0; i < N; i++) {
        mst[i] = i + 1;
    }
    if (p == mst) {
        cout << "YES" << endl;
        return 0;
    }
    bool anma = false;
    for (int i = 0; i < N; i++) {
        for (int ii = i + 1; ii < N; ii++) {
            swap(p[i], p[ii]);
            anma |= p == mst;
            swap(p[i], p[ii]);
        }
    }
    if (anma) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
