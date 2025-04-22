// Title : 이분 그래프
// Link  : https://www.acmicpc.net/problem/1707 
// Time  : 220 ms
// Memory: 6080 KB

#include <bits/stdc++.h>

using namespace std;

bool Traverse(int cur, const vector<vector<int>>& edges, vector<int8_t>& memo) {
  for (auto nxt : edges[cur]) {
    if (memo[nxt]) {
      if (memo[nxt] == memo[cur]) return false;
    } else {
      memo[nxt] = memo[cur] ^3;
      if (!Traverse(nxt, edges, memo)) return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges(v + 1);
    vector<int8_t> memo(v + 1);

    while (e--) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }

    bool ok = true;
    for (int i = 1; ok && i <= v; i++) {
      if (memo[i]) continue;
      memo[i] = 1;
      ok = Traverse(i, edges, memo);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}
