// Title : 팩토리얼5
// Link  : https://www.acmicpc.net/problem/1564
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e12;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int64_t ans = 1;
  for (int i = 2; i <= n; i++) {
    ans *= i;
    while (ans % 10 == 0) ans /= 10;
    ans %= kMod;
  }
  cout << setw(5) << setfill('0') << ans % 100000;

  return 0;
}
