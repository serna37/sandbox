#include <bits/stdc++.h>
using namespace std;
template <typename STRING = string, typename CHAR = char>
vector<pair<CHAR, int>> run_length(STRING &S) {
    vector<pair<CHAR, int>> res;
    for (auto &&x : S) {
        if (res.empty() or res.back().first != x) {
            res.emplace_back(x, 0);
        }
        res.back().second++;
    }
    return res;
}

int main() {
    int N;
    string S;
    cin >> N >> S;
    auto ans = run_length(S);
    for (auto [c, cnt] : ans) {
        cout << c << ":" << cnt << endl;
    }
    // int cur = 0;
    // for (int i = 0; i < N; i++) {
    // cur = i;
    // while (i < N and S[cur] == S[i]) i++;
    // ans = max(ans, i - cur);
    //}
}
