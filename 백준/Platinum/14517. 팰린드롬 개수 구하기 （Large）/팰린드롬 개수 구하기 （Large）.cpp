#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 10007;

int memo[1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();
  fill_n(memo, n, 1);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (s[i] == s[j]) {
        ++memo[j];
        for (int k = j + 1; k < i; k++) {
          memo[j] = (memo[j] + memo[k]) % kMod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans += memo[i];
  cout << ans % kMod;

  return 0;
}
