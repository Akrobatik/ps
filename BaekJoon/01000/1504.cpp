// Title : 특정한 최단 경로
// Link  : https://www.acmicpc.net/problem/1504
// Time  : 40 ms
// Memory: 4668 KB

#include <bits/stdc++.h>

using namespace std;

int n_nodes, n_edges;
int nodes[801];
int edges[801][801];

struct Path : public pair<int, int> {
  Path(int pos, int cost) : pair<int, int>(make_pair(pos, cost)) {}

  constexpr auto operator<=>(const Path& rhs) const {
    return second <=> rhs.second;
  }
};

int GetMin(int s, int e) {
  int memo[801];
  fill_n(memo, 801, INT_MAX);
  memo[s] = 0;

  priority_queue<Path, vector<Path>, greater<Path>> pq;
  pq.push(Path(s, 0));
  while (!pq.empty()) {
    auto [pos, cost] = pq.top();
    pq.pop();

    if (pos == e) return cost;

    for (int i = 1; i <= n_nodes; i++) {
      if (edges[pos][i] && memo[i] > cost + edges[pos][i]) {
        memo[i] = cost + edges[pos][i];
        pq.push(Path(i, cost + edges[pos][i]));
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n_nodes >> n_edges;
  for (int i = 1; i <= n_edges; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a][b] = edges[b][a] = c;
  }

  int v1, v2;
  cin >> v1 >> v2;
  int d01 = GetMin(1, v1);
  int d02 = GetMin(1, v2);
  int d12 = GetMin(v1, v2);
  int d13 = GetMin(v1, n_nodes);
  int d23 = GetMin(v2, n_nodes);
  if (d12 && d13 && d02 && (d01 || 1 == v1) && (d23 || v2 == n_nodes)) {
    cout << min<int>(d01 + d12 + d23, d02 + d12 + d13) << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
