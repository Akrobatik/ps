// Title : 단절선
// Link  : https://www.acmicpc.net/problem/11400
// Time  : 208 ms
// Memory: 14416 KB

#include <bits/stdc++.h>

using namespace std;

int idx;
int memo[100001];
vector<int> edges[100001];
vector<pair<int, int>> ans;

int Traverse(int cur, int par) {
  int res = memo[cur] = ++idx;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    if (memo[nxt]) {
      res = min<int>(res, memo[nxt]);
    } else {
      int nid = Traverse(nxt, cur);
      if (memo[cur] < nid) {
        int minn = min<int>(cur, nxt);
        ans.push_back({minn, cur ^ nxt ^ minn});
      }
      res = min<int>(res, nid);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int v, e;
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 1; i <= v; i++) {
    if (memo[i]) continue;
    Traverse(i, 0);
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto [a, b] : ans) {
    cout << a << " " << b << "\n";
  }

  return 0;
}
