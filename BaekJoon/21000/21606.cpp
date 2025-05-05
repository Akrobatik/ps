// Title : 아침 산책
// Link  : https://www.acmicpc.net/problem/21606 
// Time  : 96 ms
// Memory: 25672 KB

#include <bits/stdc++.h>

using namespace std;

int64_t ans;
string type;
vector<int> edges[200000];

int Traverse(int cur, int par) {
  if (type[cur] == '0') {
    int sum = 0;
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      int cnt = Traverse(nxt, cur);
      sum += cnt;
      ans -= (int64_t)cnt * cnt;
    }
    ans += (int64_t)sum * sum;
    return sum;
  } else {
    int sum = 0;
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      sum += Traverse(nxt, cur);
    }
    ans += sum * 2;
    return 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> type;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  Traverse(0, -1);
  cout << ans;

  return 0;
}
