// Title : Labyrinth
// Link  : https://www.acmicpc.net/problem/3482 
// Time  : 164 ms
// Memory: 3432 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<string> board;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> board;
  vector<vector<bool>> visited;
  queue<pair<int, int>> q;

  auto Push = [&](int y, int x) {
    if (board[y][x] != '.' || visited[y][x]) return;
    visited[y][x] = true;
    q.push({y, x});
  };

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m >> n;
    board.resize(n);
    for (auto& s : board) cin >> s;

    int ry = -1, rx = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] != '.') continue;
        ry = i, rx = j;
        break;
      }
      if (ry != -1 && rx != -1) break;
    }

    auto BFS = [&](int sy, int sx) -> tuple<int, int, int> {
      visited.assign(n, vector<bool>(m));

      int ad, ay, ax;
      Push(sy, sx);
      for (int i = 0; !q.empty(); i++) {
        int nq = q.size();
        while (nq--) {
          auto [y, x] = q.front();
          q.pop();

          ay = y, ax = x;
          for (auto [dy, dx] : kDelta) {
            Push(y + dy, x + dx);
          }
        }
        ad = i;
      }

      return {ad, ay, ax};
    };

    auto [ad, ay, ax] = BFS(ry, rx);
    cout << "Maximum rope length is " << get<0>(BFS(ay, ax)) << ".\n";
  }

  return 0;
}
