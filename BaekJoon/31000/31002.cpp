// Title : 그래프 변환
// Link  : https://www.acmicpc.net/problem/31002 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;
constexpr int64_t kInv2 = 5e8 + 4;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  int64_t e = n - 1;
  while (k--) {
    n = (n * e % kMod) * kInv2 % kMod;
    e = (e * 2 + kMod - 2) % kMod;
  }
  cout << n;

  return 0;
}
