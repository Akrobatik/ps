// Title : 상어의 저녁식사
// Link  : https://www.acmicpc.net/problem/1671 
// Time  : 0 ms
// Memory: 2160 KB

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

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (auto& [a, b, c] : arr) cin >> a >> b >> c;

  auto Check = [&](int i, int j) {
    auto [ia, ib, ic] = arr[i];
    auto [ja, jb, jc] = arr[j];

    if (ia >= ja && ib >= jb && ic >= jc) {
      if (ia == ja && ib == jb && ic == jc) return i < j;
      return true;
    }
    return false;
  };

  HopcroftKarp solver;
  solver.Init(n << 1, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      if (Check(i, j)) {
        solver.AddEdge((i << 1) + 1, j + 1);
        solver.AddEdge((i << 1) + 2, j + 1);
      }
    }
  }

  cout << n - solver.Solve();

  return 0;
}
