// Title : 한조 대기 중
// Link  : https://www.acmicpc.net/problem/14433 
// Time  : 80 ms
// Memory: 4972 KB

// Title : 일반 그래프 매칭
// Link  : https://www.acmicpc.net/problem/15737
// Time  : 20 ms
// Memory: 4144 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k[2];
  int n, m;
  cin >> n >> m >> k[0] >> k[1];

  int cnt[2];
  EdmondsBlossom solver;
  for (int i = 0; i < 2; i++) {
    solver.Init(n + m + 1);
    while (k[i]--) {
      int u, v;
      cin >> u >> v;
      solver.AddEdge(u, n + v, 1);
    }
    cnt[i] = solver.Solve();
  }
  cout << (cnt[0] < cnt[1] ? "네 다음 힐딱이" : "그만 알아보자");

  return 0;
}
