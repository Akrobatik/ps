// Title : 문자판
// Link  : https://www.acmicpc.net/problem/2186 
// Time  : 140 ms
// Memory: 15336 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<pair<int, int>> edges[100][100][26];
string dst;
int memo[100][100][80];

int Calc(int y, int x, int idx) {
  if (idx + 1 == dst.size()) return 1;

  auto& res = memo[y][x][idx];
  if (res != -1) return res;

  res = 0;
  for (auto [ny, nx] : edges[y][x][dst[idx + 1] - 'A']) {
    res += Calc(ny, nx, idx + 1);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  memset(memo, -1, sizeof(memo));

  int n, m, k;
  cin >> n >> m >> k;

  vector<string> board(n);
  for (auto& s : board) cin >> s;
  cin >> dst;

  auto CheckY = [&](int y) {
    return 0 <= y && y < n;
  };

  auto CheckX = [&](int x) {
    return 0 <= x && x < m;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (auto [dy, dx] : kDelta) {
        int y = i, x = j, r = k;
        while (r-- && CheckY(y += dy) && CheckX(x += dx)) {
          edges[i][j][board[y][x] - 'A'].push_back({y, x});
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dst[0] != board[i][j]) continue;
      ans += Calc(i, j, 0);
    }
  }
  cout << ans;

  return 0;
}
