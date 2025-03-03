#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-2, -1},
    {-2, 1},
    {-1, -2},
    {-1, 2},
    {2, -1},
    {2, 1},
    {1, -2},
    {1, 2}};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int l;
    cin >> l;
    int sy, sx, ty, tx;
    cin >> sy >> sx >> ty >> tx;

    vector<vector<bool>> visited(l, vector<bool>(l, false));
    queue<pair<int, int>> q;
    visited[sy][sx] = true;
    q.push({sy, sx});
    int i;
    bool found = false;
    for (i = 0; !q.empty(); i++) {
      int nq = q.size();
      while (nq--) {
        auto [cy, cx] = q.front();
        q.pop();

        if (cy == ty && cx == tx) {
          found = true;
          break;
        }

        for (auto [dy, dx] : kDelta) {
          int y = cy + dy, x = cx + dx;
          if (0 <= y && y < l && 0 <= x && x < l && !visited[y][x]) {
            visited[y][x] = true;
            q.push({y, x});
          }
        }
      }
      if (found) break;
    }
    cout << i << "\n";
  }

  return 0;
}
