#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    string S;
    cin >> N >> S;
    pair<int, int> P = {0, 0};
    vector<pair<int, int>> H;
    H.push_back(P);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            P.first++;
        } else if (S[i] == 'L') {
            P.first--;
        } else if (S[i] == 'U') {
            P.second++;
        } else {
            P.second--;
        }
        H.push_back(P);
    }
    auto m = H;
    sort(H.begin(), H.end());
    H.erase(unique(H.begin(), H.end()), H.end());
    if (H.size() != m.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
