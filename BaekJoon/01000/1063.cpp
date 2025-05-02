// Title : 킹
// Link  : https://www.acmicpc.net/problem/1063 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

pair<int, int> ReadCoord() {
  int y;
  char c;
  cin >> c >> y;
  return {8 - y, c - 'A'};
}

string ToString(int y, int x) {
  string s;
  s.push_back('A' + x);
  s.push_back('8' - y);
  return s;
}

pair<int, int> GetDelta(const string& s) {
  int dy = 0, dx = 0;
  for (auto c : s) {
    switch (c) {
      case 'L': {
        dx = -1;
      } break;
      case 'R': {
        dx = 1;
      } break;
      case 'T': {
        dy = -1;
      } break;
      case 'B': {
        dy = 1;
      } break;
    }
  }
  return {dy, dx};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto [ky, kx] = ReadCoord();
  auto [sy, sx] = ReadCoord();

  auto Move = [&](const string& s) {
    auto [dy, dx] = GetDelta(s);
    int kky = ky + dy, kkx = kx + dx;
    if (!(0 <= kky && kky < 8 && 0 <= kkx && kkx < 8)) return;
    if (sy != kky || sx != kkx) {
      ky = kky, kx = kkx;
      return;
    }
    int ssy = sy + dy, ssx = sx + dx;
    if (!(0 <= ssy && ssy < 8 && 0 <= ssx && ssx < 8)) return;
    ky = kky, kx = kkx;
    sy = ssy, sx = ssx;
  };

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    Move(s);
  }
  cout << ToString(ky, kx) << "\n"
       << ToString(sy, sx);

  return 0;
}
