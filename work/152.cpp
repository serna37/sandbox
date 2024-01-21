#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    string s;
    cin >> N >> s;
    int mi = INF, idx = 0;
    for (int i = 0; i < N; i++) {
        if (mi >= s[i] - 'a') {
            mi = s[i] - 'a';
            idx = i;
        }
    }
    if (idx == 0) {
        cout << s << endl;
        return 0;
    }
    int c = 0;
    while (c < idx) {
        if (s[c] > s[idx]) {
            swap(s[c], s[idx]);
            c++;
            while (c < N and s[c] - 'a' == mi) {
                c++;
            }
        }
        idx--;
    }
    cout << s << endl;
}
