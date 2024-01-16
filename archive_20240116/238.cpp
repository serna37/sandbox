#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] != '.') {
                continue;
            }
            set<int> st = {1, 2, 3, 4, 5};
            for (int t = 0; t < 4; t++) {
                int x = j + dx[t];
                int y = i + dy[t];
                if (G[y][x] == '.') {
                    continue;
                }
                if (x < 0 or y < 0 or W <= x or H <= y) continue;
                st.erase(G[y][x] - '0');
            }
            int a = *st.begin();
            G[i][j] = a;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << G[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
