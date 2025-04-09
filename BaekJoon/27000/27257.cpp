// Title : Любитель нулей
// Link  : https://www.acmicpc.net/problem/27257 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  while (!s.empty() && s.back() == '0') s.pop_back();

  int cnt = 0;
  for (auto c : s) cnt += (c == '0');
  cout << cnt;

  return 0;
}
