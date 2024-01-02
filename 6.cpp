#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    vector<int> dx8 = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy8 = {-1, 0, 1, -1, 1, -1, 0, 1};
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(H, vector<bool>(W, false));
    int ans = 0;
    for (int row = 0; row < H; row++) {
        for (int col = 0; col < W; col++) {
            if (vis[row][col] or S[row][col] == '.') {
                continue;
            }
            ans++;
            q.push({row, col});
            vis[row][col] = true;
            while (!q.empty()) {
                pair<int, int> tmp = q.front();
                q.pop();
                for (int i = 0; i < 8; i++) {
                    int x = dx8[i] + tmp.first;
                    int y = dy8[i] + tmp.second;
                    if (0 <= x and x < H and 0 <= y and y < W) {
                        if (!vis[x][y] and S[x][y] == '#') {
                            q.push({x, y});
                            vis[x][y] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
