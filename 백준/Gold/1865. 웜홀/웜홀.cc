#include <bits/stdc++.h>

using namespace std;

using Edge = pair<int, pair<int, int>>;
vector<Edge> edges;
int memo[501];

bool EdgeUniquePredicate(const Edge& lhs, const Edge& rhs) {
  return lhs.first == rhs.first && lhs.second.first == rhs.second.first;
}

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
      edges.push_back(make_pair(s, make_pair(e, t)));
      edges.push_back(make_pair(e, make_pair(s, t)));
    }
    for (int i = 0; i < w; i++) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back(make_pair(s, make_pair(e, -t)));
    }
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end(), EdgeUniquePredicate), edges.end());

    bool cycle = false;
    memset(memo, 0, sizeof(memo));
    for (int i = 1; i <= n; i++) {
      for (auto [s, et] : edges) {
        auto [e, t] = et;
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
