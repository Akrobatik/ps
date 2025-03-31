#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int ans, r, c;
char m[20][20];

void Traverse(int y, int x, int mask, int cnt) {
  ans = max<int>(ans, cnt + 1);
  mask |= (1 << (m[y][x] ^ 0x40));

  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (0 <= yy && yy < r && 0 <= xx && xx < c && !(mask & (1 << (m[yy][xx] ^ 0x40)))) {
      Traverse(yy, xx, mask, cnt + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> m[i][j];
    }
  }
  Traverse(0, 0, 0, 0);
  cout << ans;

  return 0;
}
