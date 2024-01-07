#include <bits/stdc++.h>
using namespace std;
int main() {
    double PI = acos(-1);
    const int INF = 1001001001;
    const long long aINF = 1001001001001001001ll;
    const int MOD = 998244353;
    const int aMOD = 100000007;
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
    vector<int> dx4 = {1, 0, -1, 0};
    vector<int> dy4 = {0, 1, 0, -1};
    vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
    vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};
    int N = 10;
    vector<int> is_P(N + 1, true);
    is_P[0] = is_P[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!is_P[i]) continue;
        for (int j = i * i; j <= N; j += i) is_P[j] = false;
    };
}
