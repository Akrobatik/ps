// Title : 열혈강호
// Link  : https://www.acmicpc.net/problem/11375 
// Time  : 212 ms
// Memory: 6120 KB

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  HopcroftKarp solver;
  solver.Init(n + 1, m + 1);
  for (int i = 1; i <= n; i++) {
    int nn;
    cin >> nn;
    while (nn--) {
      int x;
      cin >> x;
      solver.AddEdge(i, x);
    }
  }
  cout << solver.Solve();

  return 0;
}
