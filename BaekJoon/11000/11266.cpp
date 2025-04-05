// Title : 단절점
// Link  : https://www.acmicpc.net/problem/11266
// Time  : 24 ms
// Memory: 6800 KB

#include <bits/stdc++.h>

using namespace std;

int idx;
int memo[100001];
vector<int> edges[100001];
vector<int> ans;

int Traverse(int cur, int par) {
  int res = memo[cur] = ++idx;
  bool yet = true;
  int cnt = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    if (memo[nxt]) {
      res = min<int>(res, memo[nxt]);
    } else {
      int nid = Traverse(nxt, cur);
      if (yet) {
        if ((!par && ++cnt == 2) || (par && memo[cur] <= nid)) {
          ans.push_back(cur);
          yet = false;
        }
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
  for (auto a : ans) {
    cout << a << " ";
  }

  return 0;
}
