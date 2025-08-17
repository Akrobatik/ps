#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr int kTableA[4][4] = {
    {0, 0, 0, 0},
    {0, 1, -1, -1},
    {0, -1, 1, 2},
    {0, -1, 2, -1},
};

constexpr int kTableB[4][4] = {
    {0, 0, 0, 0},
    {0, -1, 3, 1},
    {0, 3, -2, -1},
    {0, 1, -1, 1},
};

pair<int, int> Delta(char c) {
  if (c == 'U') return {-1, 0};
  if (c == 'D') return {1, 0};
  if (c == 'L') return {0, -1};
  if (c == 'R') return {0, 1};
  return {0, 0};
}

int Calc(const string& s) {
  if (s.size() != 221) return -1;

  for (int i = 0; i < 111; i++) {
    if ('A' <= s[i] && s[i] <= 'C') continue;
    return -1;
  }

  vector<tup> arr(111);
  arr[0] = {s[0] - 'A' + 1, 0, 0};
  int y = 0, x = 0;
  int miny = 0, maxy = 0, minx = 0, maxx = 0;
  for (int i = 1; i < 111; i++) {
    auto [dy, dx] = Delta(s[i + 110]);
    y += dy, x += dx;
    arr[i] = {s[i] - 'A' + 1, y, x};
    miny = min<int>(miny, y), maxy = max<int>(maxy, y);
    minx = min<int>(minx, x), maxx = max<int>(maxx, x);
  }
  maxy -= miny, maxx -= minx;
  for (auto& [t, y, x] : arr) y -= miny, x -= minx;

  vector<vector<int>> board(maxy + 2, vector<int>(maxx + 2));
  for (auto [t, y, x] : arr) {
    if (board[y][x]) return -1;
    board[y][x] = t;
  }

  int score = 0;
  for (int i = 0; i <= maxy; i++) {
    for (int j = 0; j <= maxx; j++) {
      int t1 = board[i][j], t2 = board[i][j + 1], t3 = board[i + 1][j];
      score += kTableB[t1][t2] + kTableB[t1][t3];
    }
  }

  for (int i = 1; i < 111; i++) {
    auto [t1, y1, x1] = arr[i - 1];
    auto [t2, y2, x2] = arr[i];
    score += kTableA[t1][t2] - kTableB[t1][t2];
  }

  for (int i = 0; i <= maxy; i++) {
    for (int j = 0; j <= maxx; j++) {
      cerr << board[i][j] << " \n"[j == maxx];
    }
  }

  return max<int>(score, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  cout << Calc(s);

  return 0;
}