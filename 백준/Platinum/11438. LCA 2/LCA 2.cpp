#include <bits/stdc++.h>

using namespace std;

int heights[100001];
int parents[100001][18];
vector<int> edges[100001];

int LCA(int a, int b) {
  if (heights[a] > heights[b]) swap(a, b);

  uint32_t delta = heights[b] - heights[a];
  while (delta) {
    int msb = bit_width(delta) - 1;
    b = parents[b][msb];
    delta ^= (1 << msb);
  }

  while (a != b) {
    if (parents[a][0] == parents[b][0]) {
      a = parents[a][0];
      break;
    } else {
      for (int i = 1; i <= 17; i++) {
        if (parents[a][i] == parents[b][i]) {
          a = parents[a][i - 1];
          b = parents[b][i - 1];
          break;
        }
      }
    }
  }

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  queue<pair<int, int>> q;
  q.push({1, 0});
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [cur, parent] = q.front();
      q.pop();

      heights[cur] = i;
      parents[cur][0] = parent;
      for (auto child : edges[cur]) {
        if (child != parent) q.push({child, cur});
      }
    }
  }

  for (int h = 1; h <= 17; h++) {
    for (int i = 1; i <= n; i++) {
      parents[i][h] = parents[parents[i][h - 1]][h - 1];
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << "\n";
  }

  return 0;
}
