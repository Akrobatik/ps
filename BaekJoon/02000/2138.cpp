// Title : 전구와 스위치
// Link  : https://www.acmicpc.net/problem/2138 
// Time  : 0 ms
// Memory: 2392 KB

#include <bits/stdc++.h>

using namespace std;

int Calc(string s, int cnt) {
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == 0) continue;
    ++cnt;
    s[i - 1] ^= 1, s[i] ^= 1;
    if (i + 1 != n) s[i + 1] ^= 1;
  }
  if (s[n - 1]) return INT_MAX;
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s1, s2;
  cin >> n >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    s1[i] ^= s2[i];
  }

  int minn = Calc(s1, 0);
  s1[0] ^= 1, s1[1] ^= 1;
  minn = min<int>(minn, Calc(s1, 1));
  cout << (minn != INT_MAX ? minn : -1);

  return 0;
}
