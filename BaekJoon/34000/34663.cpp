// Title : 거북이 대결
// Link  : https://www.acmicpc.net/problem/34663 
// Time  : 72 ms
// Memory: 3352 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  string s[2];
  for (int i = 0; i < 2; i++) {
    cin >> s[i];
  }

  auto CheckOne = [&](int y, int x) {
    if (0 <= y && y < 2 && 0 <= x && x < n) return (s[y][x] == '.');
    return false;
  };

  auto Count = [&](int y, int x) {
    return CheckOne(y, x - 1) + CheckOne(y, x + 1) + CheckOne(y ^ 1, x);
  };

  auto Check = [&](int y, int x) {
    if (Count(y, x) == 0) return false;
    if (CheckOne(y, x - 1) && Count(y, x - 1) == 1) return true;
    if (CheckOne(y, x + 1) && Count(y, x + 1) == 1) return true;
    if (CheckOne(y ^ 1, x) && Count(y ^ 1, x) == 1) return true;
    for (int i = -1; i <= 1; i += 2) {
      if (CheckOne(y, x + i) && CheckOne(y, x + i * 2)) return true;
      if (CheckOne(y, x + i) && CheckOne(y ^ 1, x + i) && Count(y ^ 1, x + i) > 1) return true;
    }
    return false;
  };

  while (q--) {
    int cmd, y, x;
    cin >> cmd >> y >> x, --y, --x;
    if (cmd == 1) {
      s[y][x] ^= '.' ^ '#';
    } else {
      cout << (Check(y, x) ? "Kaorin\n" : "Turtle\n");
    }
  }

  return 0;
}