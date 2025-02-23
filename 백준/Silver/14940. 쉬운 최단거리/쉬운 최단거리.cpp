#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

using tup = tuple<int, int, int>;

int memo[1000][1000];
bool visited[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int cy, cx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v;
      cin >> v;
      if (v == 0) {
        visited[i][j] = true;
      } else {
        memo[i][j] = INT_MAX;
        if (v == 2) cy = i, cx = j;
      }
    }
  }

  priority_queue<tup, vector<tup>, greater<>> pq;
  pq.push({0, cy, cx});
  while (!pq.empty()) {
    auto [d, y, x] = pq.top();
    pq.pop();

    if (visited[y][x]) continue;
    visited[y][x] = true;
    memo[y][x] = d;

    for (auto [dy, dx] : kDelta) {
      int yy = y + dy, xx = x + dx;
      if (0 <= yy && yy < n && 0 <= xx && xx < m && !visited[yy][xx] && memo[yy][xx] > d + 1) {
        pq.push({d + 1, yy, xx});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << (memo[i][j] != INT_MAX ? memo[i][j] : -1) << " ";
    }
    cout << "\n";
  }

  return 0;
}
