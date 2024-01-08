#include <bits/stdc++.h>
using namespace std;
int main() {
    long long L;
    int N = 10;
    for (long long r = 0; r <= 19; r++) {
    }
    for (long long i = N - 1; i >= 0; i--) {
    }
    for (char v : "as") {
    }
    const double PI = acos(-1);
    const long long INF = 1001001001001001001ll;
    const int MOD = 998244353;
    vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
    vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
    cout << "ok" << endl;
    int ans = 0;
    int tmp = 9;
    ans = max(ans, tmp);
    ans = min(ans, tmp);
    int cl = clamp(100, 4, 80);
    vector<int> A(N);
    sort(A.begin(), A.end());
    auto itr = lower_bound(A.begin(), A.end(), 4);
    sort(A.rbegin(), A.rend());
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    string str = "5";
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    auto divFloor = [](int a, int b) -> int {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
    };
    auto divCeil = [](int a, int b) -> int {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto split = [](string s, char c) -> vector<string> {
        vector<string> S;
        string t;
        for (char v : s) {
            if (v == c) {
                if (!t.empty()) S.push_back(t);
                t.clear();
            } else {
                t += v;
            }
        }
        if (!t.empty()) S.push_back(t);
        return S;
    };
    auto digitsum = [](long long a, int N = 10) -> int {
        int ans = 0;
        while (a != 0) ans += a % N, a /= N;
        return ans;
    };
    auto is_p = [](long long num) -> bool {
        if (num == 2) return true;
        if (num < 2 || num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (long long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    };
    auto p_fact = [](int N) -> map<int, int> {
        map<int, int> P;
        for (int i = 2; i * i <= N; i++) {
            while (N % i == 0) P[i]++, N /= i;
        }
        if (N > 1) P[N]++;
        return P;
    };
    auto eratosthenes = [](long long N) -> vector<bool> {
        vector<bool> is_P(N + 1, true);
        is_P[0] = is_P[1] = false;
        for (long long i = 2; i * i <= N; i++) {
            if (!is_P[i]) continue;
            for (long long j = i * i; j <= N; j += i) is_P[j] = false;
        }
        return is_P;
    };
    auto comp = []<class T>(vector<T> vec) -> vector<T> {
        auto v = vec;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        }
        return vec;
    };
    do {
    } while (next_permutation(A.begin(), A.end()));
    for (long long bit = 0; bit < 1 << N; bit++) {
        int t = 0;
        for (int k = 0; k < N; k++) {
            if (bit & (1 << k)) {
                t += A[k];
            }
        }
        ans = min(ans, t);
    }

    vector<int> Sum(N + 1), Rev(N + 1);
    for (int i = 0; i < N; i++) {
        Sum[i + 1] = Sum[i] + A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        Rev[i] = Rev[i + 1] + A[i];
    }

    cout << "====" << endl;
    vector<int> Q(5);
    int l = 1, r = 2;
    Q[l]++;
    Q[r + 1]--;
    vector<int> S(5 + 1);
    for (int i = 0; i < 5; i++) {
        S[i + 1] = S[i] + Q[i];
    }
    for (int v : S) {
        cout << v << endl;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        for (int v : A) {
            q.push(v);
        }
    }
    while (!q.empty()) {
        auto a = q.front();
        q.pop();
        for (int v : G) {
            q.push(v);
        }
    };
}
