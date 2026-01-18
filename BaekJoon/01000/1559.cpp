// Title : 놀라운 미로
// Link  : https://www.acmicpc.net/problem/1559 
// Time  : 1632 ms
// Memory: 12852 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool vis[1 << 8][4][100][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> mat, spc;

  int n, m;
  while (cin >> n >> m && n && m) {
    mat.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == 'N') {
          mat[i][j] = 0;
        } else if (c == 'E') {
          mat[i][j] = 1;
        } else if (c == 'S') {
          mat[i][j] = 2;
        } else {
          mat[i][j] = 3;
        }
      }
    }

    int k;
    cin >> k;

    spc.assign(n, vector<int>(m, -1));
    for (int i = 0; i < k; i++) {
      int y, x;
      cin >> y >> x, --y, --x;
      spc[y][x] = i;
    }

    memset(vis, 0, sizeof(vis));
    queue<tuple<int, int, int>> q;

    auto Push = [&](int b, int t, int y, int x) {
      if (!(0 <= y && y < n && 0 <= x && x < m)) return;
      if (spc[y][x] != -1) b |= 1 << spc[y][x];
      if (vis[b][t][y][x]) return;
      vis[b][t][y][x] = true;
      q.push({b, y, x});
    };

    int ans = -1;
    Push(0, 0, 0, 0);
    for (int i = 0; !q.empty(); i++) {
      int nq = q.size();
      while (nq--) {
        auto [b, y, x] = q.front();
        q.pop();

        if (y + 1 == n && x + 1 == m && b + 1 == (1 << k)) {
          ans = i;
          break;
        }

        Push(b, (i + 1) & 3, y, x);

        auto [dy, dx] = kDelta[(mat[y][x] + i) & 3];
        Push(b, (i + 1) & 3, y + dy, x + dx);
      }
      if (ans != -1) break;
    }
    cout << ans << "\n";
  }

  return 0;
}