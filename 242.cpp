#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<tuple<string, int, int>> T;
    for (int i = 0; i < N; i++) {
        string S;
        int P;
        cin >> S >> P;
        T.push_back({S, -P, i + 1});
    }
    sort(T.begin(), T.end());
    for (int i = 0; i < N; i++) {
        cout << get<2>(T[i]) << endl;
    }
}
