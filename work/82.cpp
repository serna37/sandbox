#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
string enemy = "v>^<";
string white = ".SG";
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
    vector<vector<int>> view(H, vector<int>(W, 0));
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (A[i][j] != enemy[k]) {
                    continue;
                }
                int y = i, x = j;
                while (true) {
                    y += dy[k];
                    x += dx[k];
                    if (y < 0 or x < 0 or H <= y or W <= x) {
                        break;
                    }
                    if (white.find(A[y][x]) == string::npos) {
                        break;
                    }
                    view[y][x] = 1;
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
            if (y < 0 or x < 0 or H <= y or W <= x) {
                continue;
            }
            if (d[y][x] == -1 and white.find(A[y][x]) != string::npos and
                !view[y][x]) {
                d[y][x] = d[py][px] + 1;
                q.push({y, x});
            }
        }
    }
    cout << d[gy][gx] << endl;
}
