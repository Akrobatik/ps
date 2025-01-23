#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int s, e, t;
};

vector<Edge> edges;
int memo[501];

// bool EdgeSortPredicate(const Edge& lhs, const Edge& rhs) {
//   return lhs.s != rhs.s ? lhs.s < rhs.s : lhs.e != rhs.e ? lhs.e < rhs.e : lhs.t < rhs.t;
// }

// bool EdgeUniquePredicate(const Edge& lhs, const Edge& rhs) {
//   return lhs.s == rhs.s && lhs.e == rhs.e;
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, w;
    cin >> n >> m >> w;
    edges.clear();
    edges.reserve(m * 2 + w);
    for (int i = 0; i < m; i++) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back(Edge{s, e, t});
      edges.push_back(Edge{e, s, t});
    }
    for (int i = 0; i < w; i++) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back(Edge{s, e, -t});
    }
    // sort(edges.begin(), edges.end(), EdgeSortPredicate);
    // edges.erase(unique(edges.begin(), edges.end(), EdgeUniquePredicate), edges.end());

    bool cycle = false;
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i <= n; i++) {
      for (auto [s, e, t] : edges) {
        if (memo[e] > memo[s] + t) {
          if (i == n) {
            cycle = true;
            break;
          }
          memo[e] = memo[s] + t;
        }
      }
      if (cycle) break;
    }

    cout << (cycle ? "YES" : "NO") << "\n";
  }

  return 0;
}
