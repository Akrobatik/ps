// Title : 필사의 문자열
// Link  : https://www.acmicpc.net/problem/34051 
// Time  : 8 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  string best = s;
  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (int j = i + 1; j < n; j++) {
      if (s[i] >= s[j]) continue;
      reverse(s.begin() + i, s.begin() + j + 1);
      if (best.compare(s) < 0) best = s, ok = true;
      reverse(s.begin() + i, s.begin() + j + 1);
    }
    if (ok) break;
  }
  cout << best;

  return 0;
}