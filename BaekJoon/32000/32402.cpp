// Title : TPS
// Link  : https://www.acmicpc.net/problem/32402 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[4] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int y = 0, x = 0;

  int t;
  cin >> t;

  int dir = 0;
  while (t--) {
    string s;
    cin >> s;

    int cnt = 0;
    switch (s.back()) {
      case 'A':
        ++cnt;
      case 'S':
        ++cnt;
      case 'D':
        ++cnt;
      case 'W': {
        auto [dy, dx] = kDelta[(dir + cnt) & 3];
        y += dy, x += dx;
      } break;

      case 'R': {
        dir = (dir != 3 ? dir + 1 : 0);
      } break;

      case 'L': {
        dir = (dir ? dir - 1 : 3);
      } break;
    }

    auto [dy, dx] = kDelta[dir];
    cout << x << " " << y << " " << x - dx << " " << y - dy << "\n";
  }

  return 0;
}
