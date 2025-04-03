#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t x, y;
    cin >> x >> y;
    char s[64];
    int n = 0;
    while (x) s[n++] = x % y, x /= y;
    int half = n >> 1;
    bool ok = true;
    for (int i = 0; ok && i < half; i++) {
      ok = (s[i] == s[n - i - 1]);
    }
    cout << (ok ? "1\n" : "0\n");
  }

  return 0;
}
