#include <bits/stdc++.h>

using namespace std;

struct Kuhn {
  void Init(int _nl, int _nr) {
    nl = _nl, nr = _nr;
    right.clear(), right.resize(nr, -1);
    edges.clear(), edges.resize(nl);
  }

  void AddEdge(int l, int r) {
    edges[l].push_back(r);
  }

  int Solve() {
    for (int i = 0; i < nl; i++) {
      used.clear(), used.resize(nl);
      DFS(i);
    }

    int res = 0;
    for (int i = 0; i < nr; i++) {
      res += (right[i] != -1);
    }
    return res;
  }

 private:
  bool DFS(int l) {
    if (used[l]) return false;
    used[l] = true;
    for (auto r : edges[l]) {
      int ll = right[r];
      if (ll == -1 || DFS(ll)) {
        right[r] = l;
        return true;
      }
    }
    return false;
  }

  int nl, nr;
  vector<bool> used;
  vector<int> right;
  vector<vector<int>> edges;
};
