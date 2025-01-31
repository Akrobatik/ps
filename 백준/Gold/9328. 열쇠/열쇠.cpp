#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int rows, cols;
  char mat[100][100];
  bool visited[100][100];

  int t;
  cin >> t;
  while (t--) {
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cin >> mat[i][j];
      }
    }

    string s;
    cin >> s;
    bitset<26> keys;
    if (s[0] != '0') {
      for (char c : s) keys.set(c - 'a', true);
    }

    vector<pair<int, int>> doors[26];
    queue<pair<int, int>> q;

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < rows; i++) {
      if (mat[i][0] != '*') q.push({i, 0});
      if (mat[i][cols - 1] != '*') q.push({i, cols - 1});
    }

    for (int i = 1; i < cols - 1; i++) {
      if (mat[0][i] != '*') q.push({0, i});
      if (mat[rows - 1][i] != '*') q.push({rows - 1, i});
    }

    int sum = 0;
    while (!q.empty()) {
      auto [y, x] = q.front();
      q.pop();

      if (visited[y][x]) continue;
      if (mat[y][x] == '$') {
        ++sum;
      } else if ('a' <= mat[y][x] && mat[y][x] <= 'z') {
        keys.set(mat[y][x] - 'a', true);
        if (!doors[mat[y][x] - 'a'].empty()) {
          for (auto [dy, dx] : doors[mat[y][x] - 'a']) q.push({dy, dx});
        }
      } else if ('A' <= mat[y][x] && mat[y][x] <= 'Z') {
        doors[mat[y][x] - 'A'].push_back({y, x});
        if (!keys.test(mat[y][x] - 'A')) continue;
      }
      visited[y][x] = true;

      static constexpr int kDeltaY[] = {1, -1, 0, 0};
      static constexpr int kDeltaX[] = {0, 0, 1, -1};
      for (int i = 0; i < 4; i++) {
        int yy = y + kDeltaY[i];
        int xx = x + kDeltaX[i];
        if (0 <= yy && yy < rows && 0 <= xx && xx < cols && !visited[yy][xx]) {
          if (mat[yy][xx] == '*') continue;
          q.push({yy, xx});
        }
      }
    }

    cout << sum << "\n";
  }

  return 0;
}
