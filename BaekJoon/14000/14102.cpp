// Title : Formula
// Link  : https://www.acmicpc.net/problem/14102 
// Time  : 0 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

struct EdmondsBlossom {
  void Init(int _n) {
    n = _n;
    w.assign(n, vector<int64_t>(n, 0));
  }

  void AddEdge(int u, int v, int64_t _w) {
    w[u][v] = w[v][u] = _w;
  }

  int64_t Solve() {
    lx.assign(n, 0), ly.assign(n, 0);
    xy.assign(n, -1), yx.assign(n, -1);

    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        lx[x] = max<int>(lx[x], w[x][y]);
      }
    }

    for (int i = 0; i < n; i++) Update();

    int64_t res = 0;
    for (int x = 0; x < n; x++) {
      if (xy[x] < 0) continue;
      res += w[x][xy[x]];
    }
    return res >> 1;
  }

 private:
  static constexpr int64_t kInf = 1e14;

  void Update() {
    queue<int> q;
    slack.assign(n, kInf);
    prv.assign(n, -1);
    s.assign(n, false), t.assign(n, false);

    for (int x = 0; x < n; x++) {
      if (xy[x] >= 0) continue;
      s[x] = true;
      q.push(x);
    }

    for (;;) {
      while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y = 0; y < n; y++) {
          if (lx[x] + ly[y] != w[x][y] || t[y]) continue;

          if (yx[y] < 0) {
            int cx = x, cy = y, ty;
            while (cx >= 0) {
              ty = xy[cx];
              yx[cy] = cx;
              xy[cx] = cy;
              cx = prv[cx];
              cy = ty;
            }
            return;
          }

          t[y] = true;
          q.push(yx[y]);
          s[yx[y]] = true;
          prv[yx[y]] = x;
        }
      }

      int64_t delta = kInf;
      for (int x = 0; x < n; x++) {
        if (!s[x]) continue;
        for (int y = 0; y < n; y++) {
          if (!t[y]) delta = min<int64_t>(delta, lx[x] + ly[y] - w[x][y]);
        }
      }

      for (int i = 0; i < n; i++) {
        if (s[i]) lx[i] -= delta;
        if (t[i]) ly[i] += delta;
      }

      for (int x = 0; x < n; x++) {
        if (!s[x]) continue;
        for (int y = 0; y < n; y++) {
          if (t[y] || lx[x] + ly[y] != w[x][y]) continue;

          if (yx[y] < 0) {
            int cx = x, cy = y, ty;
            while (cx >= 0) {
              ty = xy[cx];
              yx[cy] = cx;
              xy[cx] = cy;
              cx = prv[cx];
              cy = ty;
            }
            return;
          }

          t[y] = true;
          if (!s[yx[y]]) {
            q.push(yx[y]);
            s[yx[y]] = true;
            prv[yx[y]] = x;
          }
        }
      }
    }
  }

  int n;
  vector<vector<int64_t>> w;
  vector<int64_t> lx, ly, slack;
  vector<int> xy, yx, prv;
  vector<bool> s, t;
};

int parity[30];
vector<int> edges[30];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    ++parity[a], ++parity[b];
    if (t == 0) {
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
  }

  vector<int> odd;
  for (int i = 1; i <= n; i++) {
    if (parity[i] & 1) odd.push_back(i);
  }

  int no = odd.size();
  if (no == 0) {
    cout << m;
    return 0;
  }
  if (no & 1) {
    cout << "-1";
    return 0;
  }

  vector<vector<int>> memo(no, vector<int>(no, -1));
  queue<int> q;
  for (int i = 0; i < no; i++) {
    vector<int> dist(n + 1, -1);

    dist[odd[i]] = 0;
    q.push(odd[i]);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto nxt : edges[cur]) {
        if (dist[nxt] != -1) continue;
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
    }

    for (int j = 0; j < no; j++) {
      if (dist[odd[j]] == -1) continue;
      memo[i][j] = dist[odd[j]];
    }
  }

  int maxx = 0;
  for (int i = 0; i < no; i++) {
    for (int j = i + 1; j < no; j++) {
      maxx = max<int>(maxx, memo[i][j]);
    }
  }

  EdmondsBlossom solver;
  solver.Init(no);
  for (int i = 0; i < no; i++) {
    for (int j = i + 1; j < no; j++) {
      if (memo[i][j] != -1) {
        solver.AddEdge(i, j, maxx - memo[i][j]);
      }
    }
  }

  int minn = (no >> 1) * maxx - solver.Solve();
  cout << m - minn;

  return 0;
}