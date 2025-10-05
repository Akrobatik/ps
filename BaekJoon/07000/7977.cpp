// Title : 크리스 마틴
// Link  : https://www.acmicpc.net/problem/7977 
// Time  : 0 ms
// Memory: 2168 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  int cnt[256] = {};
  for (auto c : s) ++cnt[c];

  int minn = INT_MAX, mv;
  for (auto c : {'A', 'C', 'G', 'T'}) {
    if (minn > cnt[c]) minn = cnt[c], mv = c;
  }

  cout << minn << "\n"
       << string(n, mv);

  return 0;
}