// Title : 알고스팟
// Link  : https://www.acmicpc.net/problem/1261 
// Time  : 0 ms
// Memory: 2216 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool visited[100][100];
char board[100][100];
int memo[100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  fill_n((int*)memo, 100 * 100, INT_MAX >> 1);
  memo[0][0] = 0;

  int n, m;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  priority_queue<tup, vector<tup>, greater<>> pq;
  pq.push({0, 0, 0});
  for (;;) {
    auto [d, y, x] = pq.top();
    pq.pop();

    if (visited[y][x]) continue;
    visited[y][x] = true;

    if (y + 1 == n && x + 1 == m) {
      cout << d;
      return 0;
    }

    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < m) {
        int dd = d + (board[yy][xx] == '1');
        if (memo[yy][xx] > dd) {
          memo[yy][xx] = dd;
          pq.push({dd, yy, xx});
        }
      }
    }
  }

  return 0;
}
