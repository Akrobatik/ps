// Title : XOR 최대
// Link  : https://www.acmicpc.net/problem/32073
// Time  : 116 ms
// Memory: 28288 KB

#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int n;
  string s;
  cin >> n >> s;

  int idx = 0;
  while (idx < n && s[idx] == '0') ++idx;
  if (idx == n) {
    cout << "0\n";
    return;
  }

  int zidx = idx + 1;
  while (zidx < n && s[zidx] == '1') ++zidx;

  string ss = s.substr(idx);
  if (zidx == n) {
    if (idx == 0) ss.back() ^= 1;
    cout << ss << "\n";
    return;
  }

  int oidx = zidx + 1;
  while (oidx < n && s[oidx] == '0') ++oidx;

  zidx -= idx, oidx -= idx;
  int ns = ss.size(), len = min<int>(oidx - zidx, zidx);
  for (int i = zidx; i < ns; i++) {
    if (s[i + idx - len] == '1') {
      ss[i] ^= 1;
    }
  }
  cout << ss << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
