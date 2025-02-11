#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[40001];
vector<pair<int, int>> queries[40001];
int memo[40001][2];
int ans[10001];

int Find(int id) {
  while (memo[id][1] != id) {
    int parent = memo[id][1];
    memo[id][1] = memo[parent][1];
    id = parent;
  }
  return id;
}

void Traverse(int cur, int parent, int dist) {
  memo[cur][0] = dist;
  memo[cur][1] = cur;
  for (auto [id, w] : edges[cur]) {
    if (id == parent) continue;
    Traverse(id, cur, dist + w);
    memo[id][1] = cur;
  }

  for (auto [id, ai] : queries[cur]) {
    if (memo[id][0] == 0) continue;
    ans[ai] = memo[cur][0] + memo[id][0] - (memo[Find(id)][0] << 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  while (--n) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    queries[a].push_back({b, i});
    queries[b].push_back({a, i});
  }

  Traverse(1, 0, 1);
  for (int i = 0; i < n; i++) cout << ans[i] << "\n";

  return 0;
}
