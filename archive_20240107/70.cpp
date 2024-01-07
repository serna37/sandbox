const double PI = acos(-1);
const int INF = 1001001001;
const int MOD = 998244353;

auto split = [](string str, char c) -> vector<string> {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == c) {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp != "") {
        arr.push_back(tmp);
    }
    return arr;
};
auto divCeil = [](int a, int b) -> int {
    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
};
auto divFloor = [](int a, int b) -> int {
    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
};
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
auto modinv = [](long long a, long long m) -> long long {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
};
auto eratosthenes = [](int N) -> vector<int> {
    vector<int> is_P(N + 1, true);
    is_P[0] = is_P[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!is_P[i]) continue;
        for (int j = i * i; j <= N; j += i) is_P[j] = false;
    }
    return is_P;
};
vector<int> dx = {1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};

if (x < 0 or y < 0 or W <= x or H <= y) continue;

