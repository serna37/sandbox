#include <bits/stdc++.h>
using namespace std;
void func(int n) {
}
int main() {
  int N = 10;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = N - 1; i >= 0; i--) {
  }
  for (auto v : A) {
  }
  auto func = [&](int a) -> void {

  };
  auto re = [&](auto self, int a) -> void {
    self(self, args); // recursive
  };
  vector<pair<long long,
              pair<double, pair<set<map<tuple<int, int, int>, int>>,
                                queue<stack<priority_queue<long long>>>>>>>
      a;
  const double PI = acos(-1);
  const int INF = 1001001001;
  const long long INF = 1001001001001001001ll;
  const int MOD = 998244353;
  const int MOD = 1000000007;
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {1, 0, -1, 0};
  vector<int> dx = {0, 1, 0, -1, 1, -1, 1, -1};
  vector<int> dy = {1, 0, -1, 0, 1, 1, -1, -1};
  cout << "" << endl;
  cout << fixed << setprecision(30);
  int ans = 0;
  int tmp = 0;
  ans = max(ans, tmp);
  ans = min(ans, tmp);
  sort(A.begin(), A.end());
  sort(A.rbegin(), A.rend());
  string str = "";
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  int p = __builtin_ctz(ans);
  p = __builtin_popcount(ans);
  long long pp = __builtin_popcountll(ans);
  cout << "debug_A:";                // TODO debug
  for (auto v : A) cout << " " << v; // TODO debug
  cout << endl;                      // TODO debug
  auto divCeil = []<class T>(T a, T b) -> T {
    return a / b + (((a ^ b) > 0 and a % b != 0) ? 1 : 0);
  };
  auto divFloor = []<class T>(T a, T b) -> T {
    return a / b - (((a ^ b) < 0 and a % b != 0) ? 1 : 0);
  };
  auto split = [](string s, char c) -> vector<string> {
    vector<string> S;
    string t;
    for (char v : s) {
      if (v == c) {
        if (!t.empty()) {
          S.push_back(t);
        }
        t.clear();
      } else {
        t += v;
      }
    }
    if (!t.empty()) {
      S.push_back(t);
    }
    return S;
  };
  auto digitsum = []<class T>(T a, int N = 10) -> T {
    T ans = 0;
    while (a != 0) {
      ans += a % N;
      a /= N;
    }
    return ans;
  };
  auto is_p = []<class T>(T num) -> bool {
    if (num == 2) {
      return true;
    }
    if (num < 2 || num % 2 == 0) {
      return false;
    }
    double sqrtNum = sqrt(num);
    for (T i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0) {
        return false;
      }
    }
    return true;
  };
  auto eratosthenes = []<class T>(T N) -> vector<bool> {
    vector<bool> is_P(N + 1, true);
    is_P[0] = is_P[1] = false;
    for (T i = 2; i * i <= N; i++) {
      if (!is_P[i]) {
        continue;
      }
      for (T j = i * i; j <= N; j += i) {
        is_P[j] = false;
      }
    }
    return is_P;
  };
  auto p_fact = []<class T>(T N) -> map<T, int> {
    map<T, int> P;
    for (T i = 2; i * i <= N; i++) {
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
  auto mod_pow = [&](long long a, long long n) -> long long {
    long long res = 1;
    while (n > 0) {
      if (n & 1) {
        res = res * a % MOD;
      }
      a = a * a % MOD;
      n >>= 1ll;
    }
    return res;
  };
  auto modinv_fermat = [&](long long a) -> long long {
    return mod_pow(a, MOD - 2);
  };
  vector<long long> mf;
  auto modfact = [&](int x) -> long long {
    if (mf.size() > x) {
      return mf[x];
    }
    if (mf.empty()) {
      mf.push_back(1);
    }
    for (int i = mf.size(); i <= x; i++) {
      long long next = mf.back() * i % MOD;
      mf.push_back(next);
    }
    return mf[x];
  };
  auto factorial = []<class T>(T N) -> T {
    T ans = 1;
    while (N > 0) {
      ans *= N;
      N--;
    }
    return ans;
  };
  auto mod_combination = [&](int n, int k) -> long long {
    return modfact(n) * modinv_fermat(modfact(k)) % MOD *
           modinv_fermat(modfact(n - k)) % MOD;
  };
  const int MAX = 3e5;
  long long fac[MAX], finv[MAX], inv[MAX];
  auto Extended_Euclid_inverse_calc = [&]() -> void {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
  };
  Extended_Euclid_inverse_calc();
  auto nCk = [&](int n, int k) -> long long {
    if (n < k or n < 0 or k < 0) {
      return 0;
    }
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  };
  do {
    //
  } while (next_permutation(A.begin(), A.end()));
  for (int bit = 0; bit < 1 << N; bit++) {
    long long tmp = 0;
    for (int k = 0; k < N; k++) {
      if (bit & (1ll << k)) {
        tmp |= A[k];
      }
    }
  }
  for (long long i = N; i > 0; i = (i - 1) & N) {
    cout << N - i << endl;
  }
  cout << N << endl;
  string S = "";
  string tt = "";
  int r = 0;
  for (int l = 0; l < N; l++) {
    l = r;
    if (l >= N) {
      break;
    }
    while (r < N and S[l] == S[r]) {
      ++r;
    }
    tt += S[l] + to_string(r - l);
  }
  vector<vector<int>> G(N);
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (x < 0 or y < 0 or column <= x or row <= y) {
        continue;
      };
    }
    for (int n : G[v.first]) {
      q.push({n, 0});
    }
  }
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  for (int i = 0; i < N; i++) {
    int wi = weight[i];
    int vi = value[i];
    for (int w = 0; w <= W; ++w) {
      if (w < wi) {
        dp[i + 1][w] = dp[i][w];
      } else {
        dp[i + 1][w] = max(dp[i][w], dp[i][w - wi] + vi);
      }
    }
  }
  vector<vector<int>> dp(N + 1, vector<int>(K + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    int ai = A[i];
    for (int k = 0; k <= K; ++k) {
      dp[i + 1][k] = dp[i][k];
      if (k >= ai) {
        dp[i + 1][k] = dp[i][k] or dp[i][k - ai];
      }
    }
  };
  vector<long long> S(N + 1);
  for (int i = 0; i < N; i++) {
    S[i + 1] = S[i] + A[i];
  }
  vector<int> R(N + 1);
  for (int i = N - 1; i >= 0; i--) {
    R[i] = R[i + 1] + A[i];
  }
  vector<vector<int>> S(H + 1, vector<int>(W + 1));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      S[i + 1][j + 1] = S[i + 1][j] + A[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      S[i + 1][j + 1] += S[i][j + 1];
    }
  }
  A[l]++;
  A[r + 1]--;
  auto comp = []<class T>(vector<T> vec) -> vector<T> {
    auto v = vec;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < (int)vec.size(); i++) {
      vec[i] = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
    }
    return vec;
  };
}
