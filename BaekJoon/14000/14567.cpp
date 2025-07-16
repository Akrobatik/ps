// Title : 선수과목 (Prerequisite)
// Link  : https://www.acmicpc.net/problem/14567 
// Time  : 92 ms
// Memory: 4956 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    ++deg[b];
  }

  queue<int> q;
  vector<int> ans(n + 1, 1);

  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto nxt : edges[cur]) {
      ans[nxt] = max<int>(ans[nxt], ans[cur] + 1);
      if (--deg[nxt] == 0) q.push(nxt);
    }
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";

  return 0;
}
