#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int ans = 0;
    vector<vector<char>> x(N, vector<char>(9));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> x[i][j];
            if (x[i][j] == 'x') {
                ans++;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < N; j++) {
            if (x[j][i] == 'o') {
                ans++;
                while (j < N and x[j][i] == 'o') {
                    j++;
                }
            }
        }
    }
    cout << ans << endl;
}
