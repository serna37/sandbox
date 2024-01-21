#include <bits/stdc++.h>
using namespace std;
int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<char>> B(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (B[i][j] == '.' or B[i][j] == '#') {
                continue;
            }
            int b = B[i][j] - '0';
            B[i][j] = '.';
            for (int k = 0; k < R; k++) {
                for (int l = 0; l < C; l++) {
                    if (B[k][l] == '#') {
                        if (abs(i - k) + abs(j - l) <= b) {
                            B[k][l] = '.';
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
}
