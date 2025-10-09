// Title : 뭉쳐야 산다
// Link  : https://www.acmicpc.net/problem/28277 
// Time  : 572 ms
// Memory: 48960 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<set<int>> memo(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    while (x--) {
      int v;
      cin >> v;
      memo[i].insert(v);
    }
  }

  while (m--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int a, b;
      cin >> a >> b;

      if (memo[a].size() < memo[b].size()) swap(memo[a], memo[b]);
      for (auto e : memo[b]) memo[a].insert(e);
      memo[b] = set<int>();
    } else {
      int a;
      cin >> a;
      cout << memo[a].size() << "\n";
    }
  }

  return 0;
}