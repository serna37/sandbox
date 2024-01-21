#include <bits/stdc++.h>
using namespace std;
int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> G(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (G[i][j] == '.' or G[i][j] == '#') {
                continue;
            }
            int b = G[i][j] - '0';
            for (int k = 0; k < R; k++) {
                for (int l = 0; l < C; l++) {
                    if (G[k][l] == '#') {
                        int d = abs(k - i) + abs(l - j);
                        if (d <= b) {
                            G[k][l] = '.';
                        }
                    }
                }
            }
            G[i][j] = '.';
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << G[i][j];
        }
        cout << endl;
    }
}
