// Title : Tree Cutting
// Link  : https://www.acmicpc.net/problem/7045 
// Time  : 0 ms
// Memory: 2588 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int16_t> edges[10001];
  int16_t deg[10001] = {};
  int16_t sum[10001] = {};
  int16_t maxx[10001] = {};
  bitset<10001> ok;

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
    ++deg[u], ++deg[v];
  }

  for (int i = 1; i <= n; i++) {
    sum[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    maxx[i] = 1;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (--deg[i]) continue;
    q.push(i);
  }

  int half = n >> 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    maxx[cur] = max<int16_t>(maxx[cur], n - sum[cur]);
    if (maxx[cur] <= half) ok.set(cur);

    for (auto nxt : edges[cur]) {
      if (deg[nxt] == 0) continue;
      sum[nxt] += sum[cur];
      maxx[nxt] = max<int16_t>(maxx[nxt], sum[cur]);
      if (--deg[nxt] == 0) {
        q.push(nxt);
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) continue;
    cout << i << "\n";
    ++cnt;
  }

  if (cnt == 0) cout << "NONE";

  return 0;
}
