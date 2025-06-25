// Title : 다리 만들기
// Link  : https://www.acmicpc.net/problem/2146 
// Time  : 52 ms
// Memory: 2500 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> board(n, vector<int>(n));
  vector<vector<bool>> visited(n, vector<bool>(n));
  for (auto& vec : board) {
    for (auto& e : vec) cin >> e;
  }

  auto Check = [&](int y, int x) {
    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < n && board[yy][xx] == 0) {
        return true;
      }
    }
    return false;
  };

  queue<pair<int, int>> q;
  vector<vector<pair<int, int>>> cands;
  vector<pair<int, int>>* curc;

  auto Push = [&](int y, int x) {
    if (!(0 <= y && y < n && 0 <= x && x < n) || board[y][x] == 0 || visited[y][x]) return;
    visited[y][x] = true;
    if (Check(y, x)) curc->push_back({y, x});
    q.push({y, x});
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0 || visited[i][j]) continue;

      curc = &cands.emplace_back();
      Push(i, j);
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [dy, dx] : kDelta) {
          Push(y + dy, x + dx);
        }
      }
    }
  }

  auto Calc = [](int y1, int x1, int y2, int x2) {
    return abs(y1 - y2) + abs(x1 - x2) - 1;
  };

  int minn = INT_MAX;
  int nc = cands.size();
  for (int i = 0; i < nc; i++) {
    auto& ic = cands[i];
    for (int j = i + 1; j < nc; j++) {
      auto& jc = cands[j];
      for (auto [iy, ix] : ic) {
        for (auto [jy, jx] : jc) {
          minn = min<int>(minn, Calc(iy, ix, jy, jx));
        }
      }
    }
  }
  cout << minn;

  return 0;
}
