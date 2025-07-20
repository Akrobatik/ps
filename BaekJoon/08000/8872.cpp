// Title : 빌라봉
// Link  : https://www.acmicpc.net/problem/8872 
// Time  : 168 ms
// Memory: 16104 KB

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edges[100001];
int parents[100001];
int dist[100001];
bool visited[100001];

pair<int, int> Find(int cur, int par, int sum) {
  parents[cur] = par;
  dist[cur] = sum;
  visited[cur] = true;
  pair<int, int> res = {sum, cur};
  for (auto [nxt, w] : edges[cur]) {
    if (nxt == par) continue;
    res = max<pair<int, int>>(res, Find(nxt, cur, sum + w));
  }
  return res;
}

pair<int, int> GetCentroid(int root) {
  auto [uw, u] = Find(root, 0, 0);
  auto [vw, v] = Find(u, 0, 0);

  int cur = v, cent = v, minn = INT_MAX;
  do {
    int val = max<int>(dist[cur], vw - dist[cur]);
    if (minn > val) minn = val, cent = cur;
    cur = parents[cur];
  } while (cur);
  return {minn, cent};
}

int GetDiameter(int root) {
  auto [uw, u] = Find(root, 0, 0);
  auto [vw, v] = Find(u, 0, 0);
  return vw;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, l;
  cin >> n >> m >> l;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    ++u, ++v;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }

  vector<pair<int, int>> roots;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    roots.push_back(GetCentroid(i));
  }
  sort(roots.begin(), roots.end(), greater<pair<int, int>>());

  int u = roots[0].second;
  for (int i = 1; i < roots.size(); i++) {
    int v = roots[i].second;
    edges[u].push_back({v, l});
    edges[v].push_back({u, l});
  }
  cout << GetDiameter(1);

  return 0;
}