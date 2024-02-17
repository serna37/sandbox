#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    pair<int, int> p = {0, 0};
    set<pair<int, int>> st;
    st.insert(p);
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
        if (st.find(p) != st.end()) {
            cout << "Yes" << endl;
            return 0;
        }
        st.insert(p);
    }
    cout << "No" << endl;
}
