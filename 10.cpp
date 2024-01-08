#include <bits/stdc++.h>
using namespace std;
int main() {
    auto p_fact = [](long long N) -> map<long long, int> {
        map<long long, int> P;
        for (long long i = 2; i * i <= N; i++) {
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
    auto is_p = [](long long num) -> bool {
        if (num == 2) return true;
        if (num < 2 || num % 2 == 0) return false;
        double sqrtNum = sqrt(num);
        for (long long i = 3; i <= sqrtNum; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    };

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

    int N = 20;
    vector<int> A(N);
    sort(A.begin(), A.end());
    int n = 3;
    auto itr = lower_bound(A.begin(), A.end(), n);
    if (itr != A.end() and *itr == n) {
    }
    bool exists = binary_search(A.begin(), A.end(), n);

    auto comp = []<class T>(vector<T> vec) -> vector<T> {
        auto v = vec;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        }
        return vec;
    };

    vector<int> B;
    for (int v : {2, 4, 6, 5, 8, 4}) {
        B.push_back(v);
    }
    cout << "=====" << endl;
    for (int v : B) {
        cout << v << endl;
    }
    cout << "compress" << endl;
    vector<int> C = comp(B);
    for (int v : C) {
        cout << v << endl;
    }
}
