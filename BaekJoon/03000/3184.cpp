// Title : 양
// Link  : https://www.acmicpc.net/problem/3184 
// Time  : 0 ms
// Memory: 2900 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;
  vector<string> board(r);
  for (auto& s : board) cin >> s;

  vector<int> memo(r * c), osz(r * c), vsz(r * c);
  iota(memo.begin(), memo.end(), 0);

  auto GetId = [&](int y, int x) {
    return y * c + x;
  };

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    memo[b] = a;
    osz[a] += osz[b];
    vsz[a] += vsz[b];
  };

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (board[i][j] == '#') continue;
      int id = GetId(i, j);
      if (board[i][j] == 'o') ++osz[id];
      if (board[i][j] == 'v') ++vsz[id];
      for (auto [dy, dx] : kDelta) {
        int y = i + dy, x = j + dx;
        if (y == -1 || x == -1 || board[y][x] == '#') continue;
        int jd = GetId(y, x);
        Union(id, jd);
      }
    }
  }

  int o = 0, v = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int id = GetId(i, j);
      if (id != Find(id)) continue;
      if (osz[id] > vsz[id]) {
        o += osz[id];
      } else {
        v += vsz[id];
      }
    }
  }
  cout << o << " " << v;

  return 0;
}
