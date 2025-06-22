// Title : 합분해
// Link  : https://www.acmicpc.net/problem/2225 
// Time  : 16 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9;

int memo[201][201];

int Calc(int n, int k) {
  if (n == 0) return 1;
  if (k == 0) return 0;

  auto& res = memo[n][k];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i <= n; i++) {
    res += Calc(n - i, k - 1);
    if (res >= kMod) res -= kMod;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(memo, -1, sizeof(memo));

  int n, k;
  cin >> n >> k;
  cout << Calc(n, k);

  return 0;
}
