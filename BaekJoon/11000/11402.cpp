// Title : 이항 계수 4
// Link  : https://www.acmicpc.net/problem/11402 
// Time  : 16 ms
// Memory: 17644 KB

#include <bits/stdc++.h>

using namespace std;

int arr[2000][2000];

int Power(int n, int exp, int mod) {
  int res = 1;
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

  int64_t n, k;
  int m;
  cin >> n >> k >> m;

  int fact[2000], inv[2000];
  fact[0] = 1;
  for (int i = 1; i < m; i++) fact[i] = fact[i - 1] * i % m;
  inv[m - 1] = Power(fact[m - 1], m - 2, m);
  for (int i = m - 1; i; i--) inv[i - 1] = inv[i] * i % m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= i; j++) {
      arr[i][j] = (fact[i] * inv[j] % m) * inv[i - j] % m;
    }
  }

  int res = 1;
  while (n || k) {
    res = (int64_t)res * arr[n % m][k % m] % m;
    n /= m, k /= m;
  }
  cout << res;

  return 0;
}
