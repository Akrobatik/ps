#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int ans, r, c;
char m[20][20];
unordered_set<int64_t> visited;

int64_t MakeKey(int64_t y, int64_t x, int64_t mask) {
  return (y << 48) | (x << 32) | mask;
}

void Traverse(int y, int x, int mask, int cnt) {
  auto key = MakeKey(y, x, mask);
  if (visited.contains(key)) return;
  visited.insert(key);

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
