// Title : 양갈래 배열 출력하기
// Link  : https://www.acmicpc.net/problem/31475 
// Time  : 380 ms
// Memory: 17768 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  char dir;
  cin >> n >> m >> dir;
  vector<vector<int>> board(n, vector<int>(m));

  queue<tuple<int, int, int>> q;

  auto Push = [&](int y, int x, int d, int v) {
    if (0 <= y && y < n && 0 <= x && x < m && board[y][x] == 0) {
      board[y][x] = v;
      q.push({y, x, d});
      return true;
    }
    return false;
  };

  if (dir == 'U') {
    Push(0, m >> 1, 0, 1);
  } else if (dir == 'D') {
    Push(n - 1, m >> 1, 1, 1);
  } else if (dir == 'L') {
    Push(n >> 1, 0, 2, 1);
  } else {
    Push(n >> 1, m - 1, 3, 1);
  }

  for (int i = 2; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x, d] = q.front();
      q.pop();

      auto [dy, dx] = kDelta[d];
      if (Push(y + dy, x + dx, d, i)) continue;

      int sd = (d <= 1 ? 2 : 0);
      for (int j = 0; j < 2; j++) {
        tie(dy, dx) = kDelta[sd + j];
        Push(y + dy, x + dx, sd + j, i);
      }
    }
  }

  for (auto& vec : board) {
    for (auto e : vec) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
