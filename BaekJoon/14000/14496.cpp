// Title : 그대， 그머가 되어
// Link  : https://www.acmicpc.net/problem/14496
// Time  : 0 ms
// Memory: 2312 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> trans[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b, n, m;
  cin >> a >> b >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    trans[u].push_back(v);
    trans[v].push_back(u);
  }

  bool visited[1001] = {};
  queue<int> q;
  visited[a] = true;
  q.push(a);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto cur = q.front();
      q.pop();
      if (cur == b) {
        cout << i;
        return 0;
      }

      for (auto nxt : trans[cur]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        q.push(nxt);
      }
    }
  }
  cout << "-1";

  return 0;
}
