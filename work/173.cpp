#include <bits/stdc++.h>
using namespace std;
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
string see = "v>^<";
int main() {
    int H, W;
    cin >> H >> W;
    int sy, sx, gy, gx;
    vector<vector<char>> A(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'S') {
                sy = i, sx = j;
            }
            if (A[i][j] == 'G') {
                gy = i, gx = j;
            }
        }
    }
    auto cango = [](const char &a) -> bool {
        string white = ".SG";
        return white.find(a) != string::npos;
    };
    vector<vector<bool>> seen(H, vector<bool>(W, false));
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (see[k] != A[i][j]) continue;
                int y = i + dy[k];
                int x = j + dx[k];
                while (true) {
                    if (y < 0 or x < 0 or H <= y or W <= x) break;
                    if (!cango(A[y][x])) break;
                    seen[y][x] = true;
                    y += dy[k];
                    x += dx[k];
                }
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({sy, sx});
    vector<vector<int>> d(H, vector<int>(W, -1));
    d[sy][sx] = 0;
    while (!q.empty()) {
        int py = q.front().first;
        int px = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int y = py + dy[i];
            int x = px + dx[i];
            if (y < 0 or x < 0 or H <= y or W <= x) continue;
            if (d[y][x] == -1 and !seen[y][x] and cango(A[y][x])) {
                d[y][x] = d[py][px] + 1;
                q.push({y, x});
            }
        }
    }
    cout << d[gy][gx] << endl;
}
