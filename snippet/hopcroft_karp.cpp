#include <bits/stdc++.h>

using namespace std;

struct HopcroftKarp {
  void Init(int _nl, int _nr) {
    nl = _nl, nr = _nr;
    used.clear(), used.resize(nl);
    left.clear(), left.resize(nl, -1);
    right.clear(), right.resize(nr, -1);
    dist.clear(), dist.resize(nl);
    edges.clear(), edges.resize(nl);
  }

  void AddEdge(int u, int v) {
    edges[u].push_back(v);
  }

  int Solve() {
    int res = 0;
    for (;;) {
      BFS();
      int add = 0;
      for (int i = 0; i < nl; i++) {
        add += (!used[i] && DFS(i));
      }

      if (add == 0) break;
      res += add;
    }
    return res;
  }

 private:
  static constexpr int kInf = INT_MAX >> 1;

  void BFS() {
    queue<int> q;
    for (int i = 0; i < nl; i++) {
      if (used[i]) {
        dist[i] = kInf;
      } else {
        dist[i] = 0;
        q.push(i);
      }
    }

    while (!q.empty()) {
      int l = q.front();
      q.pop();

      for (auto r : edges[l]) {
        int ll = right[r];
        if (ll != -1 && dist[ll] == kInf) {
          dist[ll] = dist[l] + 1;
          q.push(ll);
        }
      }
    }
  }

  bool DFS(int l) {
    for (auto r : edges[l]) {
      int ll = right[r];
      if (ll == -1 || (dist[ll] == dist[l] + 1 && DFS(ll))) {
        used[l] = true;
        left[l] = r;
        right[r] = l;
        return true;
      }
    }
    return false;
  }

  int nl, nr;
  vector<bool> used;
  vector<int> left, right, dist;
  vector<vector<int>> edges;
};
