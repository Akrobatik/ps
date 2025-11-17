// Title : 홍수
// Link  : https://www.acmicpc.net/problem/34697 
// Time  : 112 ms
// Memory: 12964 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> deg(n + 1);
  vector<vector<int>> g(n + 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (arr[u] == arr[v]) continue;
    if (arr[u] > arr[v]) swap(u, v);
    g[u].push_back(v);
    ++deg[v];
  }

  vector<int8_t> mask(n + 1);

  int k;
  cin >> k;
  while (k--) {
    int x;
    cin >> x;
    mask[x] = 1;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : g[cur]) {
      mask[nxt] |= mask[cur];
      if (--deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  cout << (*min_element(mask.begin() + 1, mask.end()) == 0 ? "flood" : "no flood");

  return 0;
}