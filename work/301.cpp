#include <bits/stdc++.h>
using namespace std;
template <typename T, typename F> T int_bisearch(T ok, T ng, const F &test) {
    while (abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        (test(mid) ? ok : ng) = mid;
    }
    return ok;
}
int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    long long mx = 2e18;
    long long L = lcm(N, M);
    auto test = [&](long long mid) -> bool {
        return (mid / N + mid / M - 2 * (mid / L)) >= K;
    };
    long long ok = mx, ng = 0;
    long long ans = int_bisearch(ok, ng, test);
    cout << ans << endl;
}
