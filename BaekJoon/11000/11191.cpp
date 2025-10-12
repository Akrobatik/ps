// Title : Xor Maximization
// Link  : https://www.acmicpc.net/problem/11191 
// Time  : 44 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t memo[60] = {};

  int n;
  cin >> n;
  while (n--) {
    int64_t x;
    cin >> x;
    for (int i = 59; i >= 0; i--) {
      if ((x >> i) & 1) {
        if (memo[i]) {
          x ^= memo[i];
        } else {
          memo[i] = x;
          break;
        }
      }
    }
  }

  int64_t ans = 0;
  for (int i = 59; i >= 0; i--) {
    if (!memo[i]) continue;
    ans = max<int64_t>(ans, ans ^ memo[i]);
  }
  cout << ans;

  return 0;
}