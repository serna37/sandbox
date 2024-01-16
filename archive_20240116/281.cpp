#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        int c = mp[S[i]];
        if (c == 0) {
            cout << S[i] << endl;
            mp[S[i]]++;
            continue;
        }
        cout << S[i] << "(" << c << ")" << endl;
        mp[S[i]]++;
    }
}
