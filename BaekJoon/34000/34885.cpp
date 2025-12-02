// Title : 파티로 가는 길
// Link  : https://www.acmicpc.net/problem/34885 
// Time  : 12 ms
// Memory: 30760 KB

#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<int>> ng;
vector<int> parents, depth;

void DFS(int cur, int par, int d, const vector<vector<int>>& g) {
  parents[cur] = par, depth[cur] = d;
  for (auto nxt : g[cur]) {
    if (nxt == par) continue;
    ng[cur].push_back(nxt);
    DFS(nxt, cur, d + 1, g);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  if (t == 1) {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (auto& s : board) cin >> s;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    auto Push = [&](int y, int x, int d) {
      if (!(0 <= y && y < n && 0 <= x && x < m)) return;
      if (board[y][x] == '#' || dist[y][x] != -1) return;
      dist[y][x] = d;
      q.push({y, x});
    };

    Push(0, 0, 0);
    for (int i = 1; !q.empty(); i++) {
      int nq = q.size();
      while (nq--) {
        auto [y, x] = q.front();
        q.pop();

        for (auto [dy, dx] : kDelta) {
          Push(y + dy, x + dx, i);
        }
      }
    }

    vector<vector<bool>> used(n, vector<bool>(m));
    int d = dist[n - 1][m - 1];
    int y = n - 1, x = m - 1;
    used[y][x] = true;
    for (int i = d - 1; i >= 0; i--) {
      int ny, nx;
      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (!(0 <= yy && yy < n && 0 <= xx && xx < m)) continue;
        if (dist[yy][xx] != i) continue;
        ny = yy, nx = xx;
        break;
      }
      y = ny, x = nx;
      used[y][x] = true;
    }

    string s(d, '\n');
    y = 0, x = 0;
    for (int i = 0; i < d; i++) {
      int ny, nx;
      for (int j = 0; j < 4; j++) {
        auto [dy, dx] = kDelta[j];
        int yy = y + dy, xx = x + dx;
        if (!(0 <= yy && yy < n && 0 <= xx && xx < m)) continue;
        if (!used[yy][xx] || dist[yy][xx] != i + 1) continue;
        ny = yy, nx = xx;
        s[i] = "DURL"[j];
        break;
      }
      y = ny, x = nx;
    }

    vector<vector<int>> g(d * 3 + 1);
    for (int i = 1; i <= d; i++) {
      int u = i, v = i + 1;
      g[u].push_back(v);
    }

    int idx = d + 1, cur = 0;
    if (s[0] == 'R') {
      cur = 2;
      int u = 1, v = ++idx;
      g[u].push_back(v);
    }

    if (d == 2) {
      while (idx < d * 3) {
        int u = 2, v = ++idx;
        g[u].push_back(v);
      }
    } else {
      for (int i = 1; i < d; i++) {
        int nxt = 0;
        if (s[i] == 'D') {
          nxt = 0;
        } else if (s[i] == 'U') {
          nxt = 1;
        } else if (s[i] == 'R') {
          nxt = 2;
        } else {
          nxt = 3;
        }

        int cnt = (cur == nxt ? 0 : (nxt & 1) + 1);
        while (cnt--) {
          int u = i + 1, v = ++idx;
          g[u].push_back(v);
        }
        cur = nxt;
      }

      if (idx < d * 3) {
        int base = 0;
        for (int i = 2; i <= d; i++) {
          int cnt = g[i].size();
          if (cnt < 3) continue;
          base = i;
          break;
        }

        if (base == 0) {
          for (int i = 0; i < 2; i++) {
            int u = 1, v = ++idx;
            g[u].push_back(v);
          }
          base = idx;
        }

        while (idx < d * 3) {
          int u = base, v = ++idx;
          g[u].push_back(v);
        }
      }
    }

    cout << d << "\n";
    for (int i = 1; i <= d * 3; i++) {
      for (auto nxt : g[i]) cout << i << " " << nxt << "\n";
    }
  } else {
    int d;
    cin >> d;
    int n = d * 3;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    if (d == 2) {
      if (g[1].size() == 1) {
        cout << "DR";
      } else {
        cout << "RD";
      }
      return 0;
    }

    ng.assign(n + 1, vector<int>());
    parents.resize(n + 1);
    depth.resize(n + 1);
    DFS(1, 0, 0, g);

    int leaf, mv = -1;
    for (int i = 1; i <= n; i++) {
      if (mv < depth[i]) mv = depth[i], leaf = i;
    }

    vector<int> seq;
    int cur = parents[leaf];
    while (cur) {
      seq.push_back(cur);
      cur = parents[cur];
    }
    reverse(seq.begin(), seq.end());

    int dir = 0;
    if (ng[seq[0]].size() % 2 == 0) dir = 2;
    cout << "DURL"[dir];
    for (int i = 1; i < d; i++) {
      int cnt = ng[seq[i]].size();
      int nxt = dir;
      if (cnt >= 2) {
        nxt ^= 2;
        nxt &= 2;
        if (cnt >= 3) ++nxt;
      }
      dir = nxt;
      cout << "DURL"[dir];
    }
  }

  return 0;
}