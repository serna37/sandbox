#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> c(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] != '.') {
                continue;
            }
            set<int> st = {1, 2, 3, 4, 5};
            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if (x < 0 or y < 0 or W <= x or H <= y) continue;
                if (c[y][x] == '.') {
                    continue;
                }
                int cc = c[y][x] - '0';
                st.erase(cc);
            }
            int ok = *st.begin();
            c[i][j] = ok + '0';
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << c[i][j];
        }
        cout << endl;
    }
}
