// Title : 디미 그래프
// Link  : https://www.acmicpc.net/problem/33579
// Time  : 40 ms
// Memory: 12488 KB

#include <bits/stdc++.h>

using namespace std;

int idx, cnt;
int memo[100001];
vector<int> edges[100001];

int Traverse(int cur, int par) {
  int res = memo[cur] = ++idx;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    if (memo[nxt]) {
      ++cnt;
      res = min<int>(res, memo[nxt]);
    } else {
      int nid = Traverse(nxt, cur);
      if (memo[cur] < nid) {
        int minn = min<int>(cur, nxt);
      }
      res = min<int>(res, nid);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  if (n != m) {
    cout << "NO";
    return 0;
  }

  while (m--) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int start = 0;
  for (int i = 1; i <= n; i++) {
    if (edges[i].size() >= 2) continue;
    if (edges[i].empty() || start) {
      cout << "NO";
      return 0;
    }
    start = i;
  }
  Traverse(start, 0);
  for (int i = 1; i <= n; i++) {
    if (memo[i]) continue;
    cout << "NO";
    return 0;
  }

  cout << (cnt == 2 ? "YES" : "NO");

  return 0;
}
