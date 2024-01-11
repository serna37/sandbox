#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long INF = 1001001001001001001ll;
const int MOD = 998244353;
vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
int main() {
    auto p_fact = [](int N) -> map<int, int> {
        map<int, int> P;
        for (int i = 2; i * i <= N; i++) {
            while (N % i == 0) {
                P[i]++;
                N /= i;
            }
        }
        if (N > 1) {
            P[N]++;
        }
        return P;
    };
    auto is_p = [](int num) -> bool {
        if (num == 2) {
            return true;
        }
        if (num < 2 || num % 2 == 0) {
            return false;
        }
        double sqrtNum = sqrt(num);
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    };
    auto eratosthenes = [](int N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (int i = 2; i * i <= N; i++) {
            if (!is_P[i]) {
                continue;
            }
            for (int j = i * i; j <= N; j += i) {
                is_P[j] = false;
            }
        }
        return is_P;
    };
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> S(N + 1);
    for (int i = 0; i < N; i++) {
        S[i + 1] = S[i] + A[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += lower_bound(A.begin(), A.end(), S[i] + K) - S.begin();
    }
    cout << ans << endl;
}
