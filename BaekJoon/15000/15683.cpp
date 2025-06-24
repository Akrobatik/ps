// Title : 감시
// Link  : https://www.acmicpc.net/problem/15683 
// Time  : 16 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> arr;
  vector<vector<int>> board(n + 2, vector<int>(m + 2, 6)), bcopy(n + 2, vector<int>(m + 2, 6));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> board[i][j];
      if (1 <= board[i][j] && board[i][j] <= 5) {
        arr.push_back({i, j});
      }
    }
  }

  int na = arr.size();

  auto Calc = [&](int x) {
    int dir[8] = {};
    for (int j = 0; j < na; j++, x >>= 2) {
      dir[j] = x & 3;
    }

    for (int i = 1; i <= n; i++) {
      copy(board[i].begin(), board[i].end(), bcopy[i].begin());
    }

    for (int i = 0; i < na; i++) {
      auto [y, x] = arr[i];
      int type = board[y][x];
      int dr[4] = {};
      switch (type) {
        case 1: {
          dr[0] = 1;
        } break;

        case 2: {
          dr[0] = dr[2] = 1;
        } break;

        case 3: {
          dr[0] = dr[1] = 1;
        } break;

        case 4: {
          dr[0] = dr[1] = dr[2] = 1;
        } break;

        case 5: {
          dr[0] = dr[1] = dr[2] = dr[3] = 1;
        } break;
      }

      for (int j = 0; j < 4; j++) {
        if (dr[(j + dir[i]) & 3] == 0) continue;
        auto [dy, dx] = kDelta[j];
        int yy = y, xx = x;
        while (board[yy][xx] != 6) {
          if (bcopy[yy][xx] == 0) bcopy[yy][xx] = 1;
          yy += dy, xx += dx;
        }
      }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cnt += (bcopy[i][j] == 0);
      }
    }

    return cnt;
  };

  int minn = INT_MAX;
  int limit = 1 << (na << 1);
  for (int i = 0; i < limit; i++) {
    minn = min<int>(minn, Calc(i));
  }
  cout << minn;

  return 0;
}
