#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    int H2, W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    for (int i = 0; i < H2; i++) {
        for (int j = 0; j < W2; j++) {
            cin >> B[i][j];
        }
    }
    for (int bit = 0; bit < (1 << H); bit++) {
        for (int bit2 = 0; bit2 < (1 << W); bit2++) {
            vector<int> h, w;
            for (int k = 0; k < H; k++) {
                if (bit & (1 << k)) h.push_back(k);
            }
            for (int k = 0; k < W; k++) {
                if (bit2 & (1 << k)) w.push_back(k);
            }
            if ((int)h.size() != H2 or (int) w.size() != W2) continue;
            bool alma = true;
            for (int i = 0; i < H2; i++) {
                for (int j = 0; j < W2; j++) {
                    int a = A[h[i]][w[j]];
                    alma &= a == B[i][j];
                }
            }
            if (alma) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
