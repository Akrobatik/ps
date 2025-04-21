// Title : 성곽
// Link  : https://www.acmicpc.net/problem/2234 
// Time  : 0 ms
// Memory: 2052 KB

#include <bits/stdc++.h>

using namespace std;

constexpr tuple<int, int, int> kDelta[] = {
    {-1, 0, 2}, {1, 0, 8}, {0, -1, 1}, {0, 1, 4}};

int board[50][50];
int memo[2501], cnts[2501];

int GetId(int y, int x, int m) {
  return y * m + x + 1;
}

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      int id = GetId(i, j, m);
      memo[id] = id;
    }
  }

  int rcnt = 0, rmax = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int id = GetId(i, j, m);
      if (memo[id] != id) continue;
      ++rcnt;

      auto& cnt = cnts[id];
      queue<pair<int, int>> q;
      q.push({i, j});
      while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        ++cnt;
        for (auto [dy, dx, db] : kDelta) {
          if (board[y][x] & db) continue;
          int yy = y + dy, xx = x + dx;
          if (0 <= yy && yy < n && 0 <= xx && xx < m) {
            int nxt = GetId(yy, xx, m);
            if (nxt == memo[nxt] && nxt != id) {
              memo[nxt] = id;
              q.push({yy, xx});
            }
          }
        }
      }
      rmax = max<int>(rmax, cnt);
    }
  }

  int mmax = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int id = Find(GetId(i, j, m));
      for (auto [dy, dx, db] : kDelta) {
        int yy = i + dy, xx = j + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m) {
          int nxt = Find(GetId(yy, xx, m));
          if (nxt != id) {
            mmax = max<int>(mmax, cnts[id] + cnts[nxt]);
          }
        }
      }
    }
  }

  cout << rcnt << "\n"
       << rmax << "\n"
       << mmax;

  return 0;
}
