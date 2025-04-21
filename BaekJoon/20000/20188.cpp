// Title : 등산 마니아
// Link  : https://www.acmicpc.net/problem/20188 
// Time  : 192 ms
// Memory: 37048 KB

#include <bits/stdc++.h>

using namespace std;

int64_t ans;
vector<int> edges[300001];

int Traverse(int cur, int par, int n) {
  int cnt = 1;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    int x = Traverse(nxt, cur, n);
    cnt += x;
    ans += (int64_t)x * (n - x) + (int64_t)x * (x - 1) / 2;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(1, 0, n);
  cout << ans;

  return 0;
}
