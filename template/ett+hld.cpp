#include <bits/stdc++.h>

using namespace std;

struct TreeFlatten {
  // 1-Based
  void Init(int root, const vector<vector<int>>& g) {
    int n = g.size();
    par.assign(n, 0), depth.assign(n, 0);
    in.assign(n, 0), out.assign(n, 0);
    heavy.assign(n, 0), head.assign(n, 0);

    nidx = 0;
    DFS1(root, g);
    DFS2(root, root, g);
  }

  int GetIdx(int u) {
    return in[u];
  }

  int GetParent(int u) {
    return par[u];
  }

  int GetLCA(int u, int v) {
    while (head[u] != head[v]) {
      int hu = head[u], hv = head[v];
      if (depth[hu] > depth[hv]) {
        u = par[hu];
      } else {
        v = par[hv];
      }
    }
    return depth[u] < depth[v] ? u : v;
  }

  pair<int, int> GetSubtree(int u) {
    return {in[u], out[u]};
  }

  vector<pair<int, int>> GetPath(int u, int v) {
    vector<pair<int, int>> res;
    while (head[u] != head[v]) {
      int hu = head[u], hv = head[v];
      if (depth[hu] > depth[hv]) {
        res.push_back({in[hu], in[u]});
        u = par[hu];
      } else {
        res.push_back({in[hv], in[v]});
        v = par[hv];
      }
    }
    if (depth[u] > depth[v]) swap(u, v);
    res.push_back({in[u], in[v]});
    return res;
  }

 private:
  int DFS1(int cur, const vector<vector<int>>& g) {
    int sum = 1, maxx = 0;
    for (auto nxt : g[cur]) {
      if (nxt == par[cur]) continue;
      par[nxt] = cur, depth[nxt] = depth[cur] + 1;
      int cnt = DFS1(nxt, g);
      sum += cnt;
      if (maxx < cnt) maxx = cnt, heavy[cur] = nxt;
    }
    return sum;
  }

  void DFS2(int cur, int hv, const vector<vector<int>>& g) {
    head[cur] = hv, in[cur] = ++nidx;
    if (heavy[cur]) DFS2(heavy[cur], hv, g);
    for (auto nxt : g[cur]) {
      if (nxt == par[cur] || nxt == heavy[cur]) continue;
      DFS2(nxt, nxt, g);
    }
    out[cur] = nidx;
  }

  int nidx;
  vector<int> par, depth, in, out, heavy, head;
};
