// Title : 알고리즘 수업 - 너비 우선 탐색 3
// Link  : https://www.acmicpc.net/problem/24446 
// Time  : 84 ms
// Memory: 8936 KB

#include <bits/stdc++.h>

using namespace std;

bool visited[100001];
int memo[100001];
vector<int> edges[100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, s;
  cin >> n >> m >> s;
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  memset(memo, -1, sizeof(memo));

  queue<int> q;
  visited[s] = true;
  q.push(s);
  for (int i = 0; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto cur = q.front();
      q.pop();

      memo[cur] = i;
      for (auto nxt : edges[cur]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        q.push(nxt);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << memo[i] << "\n";
  }

  return 0;
}
