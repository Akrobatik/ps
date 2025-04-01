#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
bool visited[1000001];
int memo[1000001];
vector<pair<int, int>> edges[1000001];

int Traverse(int cur) {
  visited[cur] = true;

  int cnt = 0, x = 1;
  for (auto [nxt, idx] : edges[cur]) {
    if (visited[nxt]) continue;
    cnt += Traverse(nxt);
    x ^= memo[nxt];
    if (memo[nxt]) ans.push_back(idx);
  }
  memo[cur] = x;
  return cnt + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back({v, i});
    edges[v].push_back({u, i});
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    if (Traverse(i) & 1) {
      cout << "-1";
      return 0;
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << " ";

  return 0;
}