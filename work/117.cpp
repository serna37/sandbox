#include <bits/stdc++.h>
using namespace std;
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<int> A(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    vector<int> B(W);
    for (int i = 0; i < W; i++) {
        cin >> B[i];
    }
    long long a = 0, b = 0;
    for (int i = 0; i < H; i++) {
        a += A[i];
    }
    for (int i = 0; i < W; i++) {
        b += B[i];
    }
    if (a % K != b % K) {
        cout << -1 << endl;
        return 0;
    }
    long long x = 0;
    long long mx = (long long)(K - 1) * W;
    for (int i = 0; i < H; i++) {
        x += (mx - A[i]) % K;
    }
    long long y = 0;
    long long my = (long long)(K - 1) * H;
    for (int i = 0; i < W; i++) {
        y += (my - B[i]) % K;
    }
    long long ans = (long long)(K - 1) * H * W - max(x, y);
    cout << ans << endl;
}
