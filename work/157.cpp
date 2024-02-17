#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin >> S;
    deque<char> T;
    int N = S.size();
    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            ok = !ok;
            continue;
        }
        if (ok) {
            if (!T.empty() and T.back() == S[i]) {
                T.pop_back();
                continue;
            }
            T.push_back(S[i]);
        } else {
            if (!T.empty() and T.front() == S[i]) {
                T.pop_front();
                continue;
            }
            T.push_front(S[i]);
        }
    }
    if (ok) {
        while (!T.empty()) {
            cout << T.front();
            T.pop_front();
        }
    } else {
        while (!T.empty()) {
            cout << T.back();
            T.pop_back();
        }
    }
    cout << endl;
}
