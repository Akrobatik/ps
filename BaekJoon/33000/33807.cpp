// Title : Minimum Spanning Arborescence
// Link  : https://www.acmicpc.net/problem/33807 
// Time  : 548 ms
// Memory: 2416 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 998244353;

int64_t Power(int64_t x, int64_t exp) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * x % kMod;
    x = x * x % kMod;
    exp >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> deg(n + 1);
  while (m--) {
    int x;
    cin >> x >> x;
    ++deg[x];
  }

  int maxx = *max_element(deg.begin(), deg.end()) + 2;
  vector<int> inv(maxx + 1), ipow(maxx + 1);
  int64_t fact = 1;
  for (int i = 2; i <= maxx; i++) fact = fact * i % kMod;
  inv[maxx] = Power(fact, kMod - 2);
  for (int i = maxx; i; i--) inv[i - 1] = (int64_t)inv[i] * i % kMod;

  int ik = Power(k, kMod - 2);
  ipow[0] = 1;
  for (int i = 1; i <= maxx; i++) ipow[i] = (int64_t)ipow[i - 1] * ik % kMod;

  auto Calc = [&](int x) {
    int64_t res = 0;
    for (int i = 1; i <= k; i++) {
      res = (res + Power(i, x)) % kMod;
    }
    return res;
  };

  vector<int> memo(maxx, -1);
  for (int i = 2; i <= n; i++) {
    int x = deg[i];
    if (memo[x] != -1) continue;
    memo[x] = Calc(x);
  }

  int64_t ans = 0;
  for (int i = 2; i <= n; i++) {
    int x = deg[i];
    ans = (ans + (int64_t)memo[x] * ipow[x]) % kMod;
  }
  cout << ans;

  return 0;
}
