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
    long long suma = 0, sumb = 0;
    for (int i = 0; i < H; i++) {
        suma += A[i];
    }
    for (int i = 0; i < W; i++) {
        sumb += B[i];
    }
    if (suma % K != sumb % K) {
        cout << -1 << endl;
        return 0;
    }
    long long needx = 0;
    long long xmax = (long long)(K - 1) * W;
    for (int i = 0; i < H; i++) {
        needx += (xmax - A[i]) % K;
    }
    long long needy = 0;
    long long ymax = (long long)(K - 1) * H;
    for (int i = 0; i < W; i++) {
        needy += (ymax - B[i]) % K;
    }
    long long ans = (long long)(K - 1) * H * W - max(needx, needy);
    cout << ans << endl;
}
