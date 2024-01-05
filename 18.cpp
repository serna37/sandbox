#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = 1001001001;
const long long INF = 1001001001001001001ll;
const int MOD = 998244353;
const int MOD = 100000007;
auto modpow = [](long long a, long long n, long long mod) -> long long {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
};
auto is_prime = [](int num) -> bool {
    if (num == 2) return true;
    if (num < 2 || num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
};
auto compress = []<class T>(vector<T> vec) -> vector<T> {
    auto v = vec;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < (int)vec.size(); i++) {
        vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
    }
    return vec;
};
vector<int> is_P(N + 1, true);
is_P[0] = is_P[1] = false;
for (int i = 2; i * i <= N; i++) {
    if (!is_P[i]) continue;
    for (int j = i * i; j <= N; j += i) is_P[j] = false;
}
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};
if (x < 0 or y < 0 or column <= x or row <= y) continue;
int main() {
    int N = 10;
    for (int i = 0; i < N; i++) {
    }
    for (long long i = 0; i < N; i++) {
    }
    for (int v : {1, 2, 3}) {
    }
}
