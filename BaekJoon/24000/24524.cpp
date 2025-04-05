// Title : 아름다운 문자열
// Link  : https://www.acmicpc.net/problem/24524
// Time  : 8 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;
  int table[256] = {};
  int nt = 0;
  for (auto c : t) table[c] = ++nt;
  int memo[27] = {INT_MAX, };
  for (auto c : s) {
    int id = table[c];
    if (id && memo[id - 1] > memo[id]) ++ memo[id];
  }
  cout << memo[nt];

  return 0;
}
