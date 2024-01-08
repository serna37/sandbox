#include <bits/stdc++.h>
using namespace std;
int main() {
    auto divCeil = [](long long a, long long b) -> long long {
        return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
    };
    auto divFloor = [](long long a, long long b) -> long long {
        return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
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

    auto is_p = [](long long num) -> bool {
        if (num == 2) return true;
        if (num < 2 || num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (long long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
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
    auto p_fact = [](long long N) -> map<long long, int> {
        map<long long, int> P;
        for (long long i = 2; i * i <= N; i++) {
            while (N % i == 0) P[i]++, N /= i;
        }
        if (N > 1) P[N]++;
        return P;
    };
}
