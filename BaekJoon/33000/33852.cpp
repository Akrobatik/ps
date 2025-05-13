// Title : PNUPC 1K9
// Link  : https://www.acmicpc.net/problem/33852 
// Time  : 16 ms
// Memory: 2668 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int k, p;
  cin >> s >> k >> p;

  for (auto& e : s) {
    if (e <= '9') {
      e -= '0';
    } else {
      e -= 'A' - 10;
    }
  }

  int n = s.size(), x = 1;
  vector<int> w(n);
  for (auto& e : views::reverse(w)) e = x, x = x * 36 % p;

  int org = 0;
  for (int i = 0; i < n; i++) {
    org = (org + w[i] * s[i]) % p;
  }

  if (org == k) {
    cout << "0";
    return 0;
  }

  bool ok = false;
  for (int i = 0; !ok && i < n; i++) {
    for (int j = 0; !ok && j < 36; j++) {
      int cur = (org + (j - s[i]) * w[i]) % p;
      if (cur < 0) cur += p;
      ok = (cur == k);
    }
  }

  if (ok) {
    cout << "1";
    return 0;
  }

  cout << (n == 1 ? "-1" : "2");

  return 0;
}
