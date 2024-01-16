#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int ii = 0; ii < W; ii++) {
            cin >> G[i][ii];
        }
    }
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (G[row][col] != '.') {
                continue;
            }
            set<int> st = {1, 2, 3, 4, 5};
            for (int i = 0; i < 4; i++) {
                int x = col + dx[i];
                int y = row + dy[i];
                if (x < 0 or y < 0 or W <= x or H <= y) continue;
                if (G[y][x] == '.') {
                    continue;
                }
                st.erase(G[y][x] - '0');
            }
            int c = *st.begin();
            G[row][col] = c + '0';
        }
    }
    for (int i = 0; i < H; i++) {
        for (int ii = 0; ii < W; ii++) {
            cout << G[i][ii];
        }
        cout << endl;
    }
    cout << endl;
}
