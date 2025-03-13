#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kMod = 1e9 + 9;
constexpr int64_t kBase = 31;

int64_t power[1000001], h[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  power[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    power[i] = (power[i - 1] * kBase) % kMod;
  }

  string s;

  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    int n = s.size();
    h[1] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
      h[i + 1] = (h[i] + power[i] * (s[i] - 'a' + 1)) % kMod;
    }

    int b = 0, half = n >> 1, ans = 0;
    for (int i = 0; i < half; i++) {
      if ((h[i + 1] - h[b] + kMod) % kMod * power[n - b - i - 1] % kMod ==
          (h[n - b] - h[n - i - 1] + kMod) % kMod) {
        ans += 2;
        b = i + 1;
      }
    }
    cout << ans + (b != half || (n & 1)) << "\n";
  }

  return 0;
}
