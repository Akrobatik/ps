// Title : 프랙탈과 점
// Link  : https://www.acmicpc.net/problem/34517 
// Time  : 52 ms
// Memory: 2144 KB

#include <bits/stdc++.h>

using namespace std;

int64_t Read() {
  string s;
  cin >> s;

  int64_t sign = s[0] == '-' ? -1 : 1;
  if (sign == -1) s = s.substr(1);

  istringstream iss(s);

  int64_t a, b;
  char c;
  iss >> a >> c >> b;
  return sign * (a * 1000 + b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t a, b, l, k;
    cin >> a >> b >> l >> k;
    int64_t p = Read() - a * 1000, q = Read() - b * 1000;

    int64_t len = 1000;
    for (int i = 0; i < k; i++) len *= 3;

    if (!(0 <= p && p <= len && 0 <= q && q <= len)) {
      cout << "0\n";
      continue;
    }

    bool ok = [&](this auto&& self, int64_t y, int64_t x, int64_t z, int lv) {
      if (lv == l) return true;

      z /= 3;
      int64_t z2 = z + z;
      if (z < y && y < z2 && z < x && x < z2) return false;
      return self(y % z, x % z, z, lv + 1);
    }(q, p, len, 0);

    cout << (ok ? "1\n" : "0\n");
  }

  return 0;
}