#include <bits/stdc++.h>

using namespace std;

struct HopcroftKarp {
  void Init(int _nl, int _nr) {
    nl = _nl, nr = _nr;
    left.clear(), left.resize(nl + 1);
    right.clear(), right.resize(nr + 1);
    dist.clear(), dist.resize(nl + 1);
    edges.clear(), edges.resize(nl + 1);
  }

  void AddEdge(int u, int v) {
    edges[u].push_back(v);
  }

  int Solve() {
    int res = 0;
    while (BFS()) {
      for (int i = 1; i <= nl; i++) {
        if (left[i]) continue;
        res += DFS(i);
      }
    }
    return res;
  }

 private:
  static constexpr int kInf = INT_MAX >> 1;

  bool BFS() {
    queue<int> q;
    for (int i = 1; i <= nl; i++) {
      if (left[i]) {
        dist[i] = kInf;
      } else {
        dist[i] = 0;
        q.push(i);
      }
    }
    dist[0] = kInf;

    while (!q.empty()) {
      int l = q.front();
      q.pop();

      if (dist[l] >= dist[0]) continue;

      for (auto r : edges[l]) {
        int ll = right[r];
        if (dist[ll] == kInf) {
          dist[ll] = dist[l] + 1;
          q.push(ll);
        }
        if (ll == 0 && dist[0] == kInf) {
          dist[0] = dist[l] + 1;
        }
      }
    }
    return dist[0] != kInf;
  }

  bool DFS(int l) {
    for (auto r : edges[l]) {
      int ll = right[r];
      if (ll == 0 || (dist[ll] == dist[l] + 1 && DFS(ll))) {
        left[l] = r;
        right[r] = l;
        return true;
      }
    }
    dist[l] = kInf;
    return false;
  }

  int nl, nr;
  vector<int> left, right, dist;
  vector<vector<int>> edges;
};
