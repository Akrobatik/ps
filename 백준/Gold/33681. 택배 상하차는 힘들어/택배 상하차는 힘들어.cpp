#include <bits/stdc++.h>

using namespace std;

int64_t ans;
int memo[100001];
vector<int> edges[100001];

int64_t Traverse(int cur, int par) {
  int64_t sum = 0, maxx = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    int64_t x = Traverse(nxt, cur);
    sum += x;
    maxx = max<int64_t>(maxx, x);
  }
  ans += memo[cur] + ((sum - maxx) << 1);
  return sum + memo[cur];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> memo[i];
    ans += memo[i];
  }
  ans -= memo[1];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (auto nxt : edges[1]) {
    Traverse(nxt, 1);
  }
  cout << ans;

  return 0;
}
