// Title : 그룹 단어 체커
// Link  : https://www.acmicpc.net/problem/1316 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t, cnt = 0;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    bool check[256] = {};
    bool ok = true;
    int idx = 0;
    while (idx < s.size()) {
      int x = s[idx];
      if (check[x]) {
        ok = false;
        break;
      }
      check[x] = true;

      while (idx < s.size() && s[idx] == x) ++idx;
    }
    cnt += ok;
  }
  cout << cnt;

  return 0;
}
