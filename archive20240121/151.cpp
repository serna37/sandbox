#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    set<pair<int, int>> st;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    pair<int, int> p = {0, 0};
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            p.first++;
        } else if (S[i] == 'L') {
            p.first--;
        } else if (S[i] == 'U') {
            p.second++;
        } else {
            p.second--;
        }
        H--;
        if (H < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (H < K and st.count(p)) {
            H = K;
            st.erase(p);
        }
    }
    cout << "Yes" << endl;
}
