// Title : 내리막 길
// Link  : https://www.acmicpc.net/problem/1520 
// Time  : 20 ms
// Memory: 4772 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int board[500][500], memo[500][500];
bool visited[500][500];

int Traverse(int y, int x, int n, int m) {
  if (y + 1 == n && x + 1 == m) return 1;

  if (visited[y][x]) return memo[y][x];
  visited[y][x] = true;

  int res = 0;
  for (auto [dy, dx] : kDelta) {
    int yy = y + dy, xx = x + dx;
    if (0 <= yy && yy < n && 0 <= xx && xx < m && board[y][x] > board[yy][xx]) {
      res += Traverse(yy, xx, n, m);
    }
  }
  return memo[y][x] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }
  cout << Traverse(0, 0, n, m);

  return 0;
}