// Title : 선수과목 (Prerequisite)
// Link  : https://www.acmicpc.net/problem/14567 
// Time  : 92 ms
// Memory: 4948 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  vector<int> ans(n + 1, 1);
  for (int i = 1; i <= n; i++) {
    for (auto nxt : edges[i]) ans[nxt] = max<int>(ans[nxt], ans[i] + 1);
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";

  return 0;
}
