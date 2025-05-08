// Title : Eight puzzle
// Link  : https://www.acmicpc.net/problem/11112 
// Time  : 84 ms
// Memory: 3940 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int board[3][3];
  auto bptr = (int*)board;
  for (int i = 0; i < 9; i++) bptr[i] = i;

  int fact[] = {40320, 5040, 720, 120, 24, 6, 2, 1, 1};
  auto GetState = [&]() {
    int rem[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int res = 0;
    for (int i = 0; i < 9; i++) {
      int x = bptr[i];
      res += fact[i] * rem[x];
      while (++x != 9) --rem[x];
    }
    return res;
  };

  auto MakeBoard = [&](int id) {
    int digit[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int i = 9;
    for (int i = 0; i < 9; i++) {
      int x = id / fact[i];
      id %= fact[i];
      bptr[i] = digit[x];
      for (int j = x + 1; j + i < 9; j++) swap(digit[j - 1], digit[j]);
    }
  };

  int memo[362880];
  bool visited[362880] = {};
  queue<pair<int, int>> q;

  auto Push = [&](int v, int y, int x) {
    if (visited[v]) return;
    visited[v] = true;
    q.push({v, (y << 2) | x});
  };

  Push(0, 2, 2);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [v, yx] = q.front();
      q.pop();

      memo[v] = i;
      int y = yx >> 2, x = yx & 3;
      MakeBoard(v);

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < 3 && 0 <= xx && xx < 3) {
          swap(board[y][x], board[yy][xx]);
          int nxt = GetState();
          Push(nxt, yy, xx);
          swap(board[y][x], board[yy][xx]);
        }
      }
    }
  }

  auto GetValue = [](char c) -> int {
    if (c == '#') return 8;
    return c - '1';
  };

  int t;
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; i++) {
      string s;
      cin >> s;
      board[i][0] = GetValue(s[0]);
      board[i][1] = GetValue(s[1]);
      board[i][2] = GetValue(s[2]);
    }

    int id = GetState();
    if (visited[id]) {
      cout << memo[id] << "\n";
    } else {
      cout << "impossible\n";
    }
  }

  return 0;
}