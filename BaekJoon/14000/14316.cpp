// Title : Sherlock and Watson Gym Secrets (Small)
// Link  : https://www.acmicpc.net/problem/14316 
// Time  : 32 ms
// Memory: 2336 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int64_t Power(int64_t n, int64_t exp, int64_t mod) {
  int64_t res = 1 % mod;
  n %= mod;
  while (exp) {
    if (exp & 1) res = res * n % mod;
    n = n * n % mod;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> arr, brr;

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int64_t a, b, n, k;
    cin >> a >> b >> n >> k;
    arr.assign(k, 0), brr.assign(k, 0);

    int64_t ans = 0;
    int limit = min<int64_t>(n, k);
    for (int i = 1; i <= limit; i++) {
      int ai = Power(i, a, k), bi = Power(i, b, k);
      int add = ((n - i) / k + 1) % kMod;
      if ((arr[ai] += add) >= kMod) arr[ai] -= kMod;
      if ((brr[bi] += add) >= kMod) brr[bi] -= kMod;
      if ((ai + bi) % k == 0) ans = (ans - add + kMod) % kMod;
    }

    for (int i = 0; i < k; i++) {
      ans = (ans + (int64_t)arr[i] * brr[(k - i) % k]) % kMod;
    }

    cout << "Case #" << tc << ": " << ans << "\n";
  }

  return 0;
}
