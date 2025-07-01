// Title : 우수 마을
// Link  : https://www.acmicpc.net/problem/1949 
// Time  : 4 ms
// Memory: 3232 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[10001];
int memo[10001][2];

void Traverse(int cur, int par) {
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    Traverse(nxt, cur);
    memo[cur][0] += max<int>(memo[nxt][0], memo[nxt][1]);
    memo[cur][1] += memo[nxt][0];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> memo[i][1];
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(1, 0);

  cout << max<int>(memo[1][0], memo[1][1]);

  return 0;
}
