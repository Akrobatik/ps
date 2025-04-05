// Title : Palindromic Partitions
// Link  : https://www.acmicpc.net/problem/15250
// Time  : 56 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 131;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;

  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    int ans = 0;
    int n = s.size(), half = n >> 1;
    int l = 0, r = n, last = 0;
    int64_t h1 = 0, h2 = 0, power = 1;
    for (int i = 0; i < half; i++) {
      h1 = (h1 + s[l++] * power) % kMod;
      h2 = (h2 * kBase + s[--r]) % kMod;
      if (h1 == h2) {
        ans += 2;
        h1 = h2 = 0;
        power = 1;
        last = l;
      } else {
        power = (power * kBase) % kMod;
      }
    }
    cout << ans + (last != l || (n & 1)) << "\n";
  }

  return 0;
}
