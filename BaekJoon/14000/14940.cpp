// Title : 쉬운 최단거리
// Link  : https://www.acmicpc.net/problem/14940
// Time  : 24 ms
// Memory: 4956 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

short memo[1000][1000];
bool visited[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      memo[i][j] = c;
    }
  }

  int cy, cx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (memo[i][j] ^ '2') continue;
      cy = i, cx = j;
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = memo[i][j] == '0';
      memo[i][j] = visited[i][j] - 1;
    }
  }

  queue<int> q;
  visited[cy][cx] = true;
  q.push((cy << 16) | cx);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto yx = q.front();
      q.pop();

      int y = yx >> 16, x = yx & 0xFFFF;
      memo[y][x] = i;
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy && yy < n && 0 <= xx && xx < m && !visited[yy][xx]) {
          visited[yy][xx] = true;
          q.push((yy << 16) | xx);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << memo[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
