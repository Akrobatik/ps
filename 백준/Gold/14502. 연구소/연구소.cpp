#include <bits/stdc++.h>

using namespace std;

struct Board {
  Board(int _rows, int _cols)
      : cells(_rows * _cols, 0), rows(_rows), cols(_cols) {}

  int* operator[](int row) { return cells.data() + row * cols; }

  int CountSafeCells() {
    int cnt = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (operator[](i)[j] == 0) cnt++;
      }
    }
    return cnt;
  }

  void SpreadVirus(const vector<pair<int, int>>& viruses) {
    bool visited[8][8];
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    for (auto& virus : viruses) {
      visited[virus.first][virus.second] = true;
      q.push(virus);
    }

    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      static constexpr int dx[] = {1, -1, 0, 0};
      static constexpr int dy[] = {0, 0, 1, -1};
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (0 <= xx && xx < cols && 0 <= yy && yy < rows &&
            !visited[yy][xx] && operator[](yy)[xx] == 0) {
          visited[yy][xx] = true;
          operator[](yy)[xx] = 2;
          q.push(make_pair(yy, xx));
        }
      }
    }
  }

  vector<int> cells;
  int rows, cols;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  Board board(n, m);
  vector<pair<int, int>> blanks;
  vector<pair<int, int>> viruses;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v;
      cin >> v;
      board[i][j] = v;
      if (v == 0)
        blanks.push_back(make_pair(i, j));
      else if (v == 2)
        viruses.push_back(make_pair(i, j));
    }
  }

  int nb = blanks.size();
  vector<uint8_t> masks(nb, 0);
  masks[nb - 3] = masks[nb - 2] = masks[nb - 1] = 1;

  int ans = 0;
  for (int i = 0; i < nb; i++) {
    for (int j = i + 1; j < nb; j++) {
      for (int k = j + 1; k < nb; k++) {
        Board new_board = board;
        new_board[blanks[i].first][blanks[i].second] = 1;
        new_board[blanks[j].first][blanks[j].second] = 1;
        new_board[blanks[k].first][blanks[k].second] = 1;
        new_board.SpreadVirus(viruses);
        ans = max<int>(ans, new_board.CountSafeCells());
      }
    }
  }

  cout << ans << endl;

  return 0;
}
