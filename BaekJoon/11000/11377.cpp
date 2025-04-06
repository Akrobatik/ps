// Title : 열혈강호 3
// Link  : https://www.acmicpc.net/problem/11377 
// Time  : 28 ms
// Memory: 5592 KB

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

  void ReserveEdge(int u, int sz) {
    edges[u].reserve(sz);
  }

  void AddEdge(int u, int v) {
    edges[u].push_back(v);
  }

  int Solve(int k) {
    int res = 0;
    while (BFS()) {
      for (int i = 1; i <= (nl >> 1); i++) {
        if (left[i]) continue;
        res += DFS(i);
      }
    }

    int add = 0;
    while (BFS2()) {
      for (int i = 1; i <= (nl >> 1); i++) {
        if (left[i + (nl >> 1)]) continue;
        add += DFS(i + (nl >> 1));
      }
    }

    return res + min<int>(add, k);
  }

 private:
  static constexpr int kInf = INT_MAX >> 1;

  bool BFS2() {
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

  bool BFS() {
    queue<int> q;
    for (int i = 1; i <= (nl >> 1); i++) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  HopcroftKarp solver;
  solver.Init(n << 1, m);
  for (int i = 1; i <= n; i++) {
    int nn;
    cin >> nn;
    solver.ReserveEdge(i, nn);
    while (nn--) {
      int x;
      cin >> x;
      solver.AddEdge(i, x);
      solver.AddEdge(i + n, x);
    }
  }
  cout << solver.Solve(k);

  return 0;
}
