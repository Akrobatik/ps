// Title : 바이러스
// Link  : https://www.acmicpc.net/problem/2606
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int memo[101];

int Find(int id) {
  while (id != memo[id]) {
    int parent = memo[id];
    id = memo[id] = memo[parent];
  }
  return id;
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return;
  if (a > b) swap(a, b);
  memo[b] = a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  iota(memo, memo + n + 1, 0);
  while (m--) {
    int u, v;
    cin >> u >> v;
    Union(u, v);
  }

  int ans = 0;
  for (int i = 2; i <= n; i++) ans += (Find(i) == 1);
  cout << ans;

  return 0;
}
