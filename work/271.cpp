#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<set<int>> A = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
    int N = A.size();
    int x, y;
    cin >> x >> y;
    bool alma = true;
    for (int i = 0; i < N; i++) {
        auto st = A[i];
        alma &= st.find(x) != st.end() ^ st.find(y) == st.end();
    }
    cout << (alma ? "Yes" : "No") << endl;
}
