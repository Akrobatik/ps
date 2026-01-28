// Title : 바바와 깃발 게임
// Link  : https://www.acmicpc.net/problem/35185 
// Time  : 0 ms
// Memory: 3184 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> m >> s;

  vector<int> memo;
  auto F = [&](int x) {
    memo.assign(n + 1, 0);
    for (auto c : s) {
      ++memo[x];
      x = clamp<int>(x + (c == 'L' ? -1 : 1), 1, n);
    }
    return memo[x] ? 0 : x;
  };

  int lv = F(1), rv = F(n);
  if (max<int>(lv, rv) == 0) {
    cout << "DEFEAT";
  } else {
    cout << "WIN\n"
         << (lv > rv ? 1 : n) << " " << max<int>(lv, rv);
  }

  return 0;
}