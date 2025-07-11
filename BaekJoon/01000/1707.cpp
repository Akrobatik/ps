// Title : 이분 그래프
// Link  : https://www.acmicpc.net/problem/1707 
// Time  : 172 ms
// Memory: 2176 KB

#include <bits/stdc++.h>

using namespace std;

int memo[20001], color[20001];

pair<int, int> Find(int id) {
  if (memo[id] == id) return {id, 0};
  auto [par, col] = Find(memo[id]);
  return {memo[id] = par, color[id] ^= col};
}

bool Union(int a, int b) {
  auto [pa, ca] = Find(a);
  auto [pb, cb] = Find(b);
  if (pa == pb) return ca != cb;
  memo[pb] = pa;
  color[pb] = ca ^ cb ^ 1;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    iota(memo, memo + n + 1, 0);
    memset(color, 0, (n + 1) * sizeof(int));

    bool ok = true;
    while (m--) {
      int u, v;
      cin >> u >> v;
      if (ok) ok = Union(u, v);
    } 
    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}