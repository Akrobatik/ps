// Title : IOIOI
// Link  : https://www.acmicpc.net/problem/5525
// Time  : 12 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ans = 0;
  int b = 0;
  while ((b = s.find_first_of('I', b)) != string::npos) {
    int cnt = 0;
    for (++b; b < m - 1; b += 2) {
      if (s[b] != 'O' || s[b + 1] != 'I') break;
      ++cnt;
    }
    if (cnt >= n) ans += cnt - n + 1;
  }
  cout << ans;

  return 0;
}
