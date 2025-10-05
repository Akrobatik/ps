// Title : 문자열 복사
// Link  : https://www.acmicpc.net/problem/2195 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, p;
  cin >> s >> p;
  int ns = s.size(), np = p.size();

  int idx = 0, ans = 0;
  while (idx < np) {
    ++ans;
    int maxx = 0;
    for (int i = 0; i < ns; i++) {
      int cnt = 0;
      while (idx + cnt < np && i + cnt < ns && p[idx + cnt] == s[i + cnt]) ++cnt;
      maxx = max<int>(maxx, cnt);
    }
    idx += maxx;
  }
  cout << ans;

  return 0;
}