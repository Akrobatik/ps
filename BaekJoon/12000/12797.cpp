// Title : 연금술
// Link  : https://www.acmicpc.net/problem/12797 
// Time  : 4 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

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

  int n, m;
  cin >> n >> m;
  vector<int> arr(m);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end());

  vector<int> brr(m);
  for (int i = 0; i < m; i++) {
    int64_t x = 1;
    for (int j = 0; j < m; j++) {
      if (i == j) continue;
      int64_t d = ((int64_t)arr[i] - arr[j] + kMod) % kMod;
      x = x * d % kMod;
    }
    brr[i] = Power(x, kMod - 2);
  }

  int64_t ans = 0;
  for (int i = 0; i < m; i++) {
    ans = (ans + Power(arr[i], n + m - 1) * brr[i]) % kMod;
  }
  cout << ans;

  return 0;
}
