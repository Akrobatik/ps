// Title : 으악그래프
// Link  : https://www.acmicpc.net/problem/35112 
// Time  : 184 ms
// Memory: 2412 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    memo[b] = a;
    return true;
  };

  int cnt = 0;
  while (m--) {
    int u, v;
    cin >> u >> v;
    cnt += Union(u, v) ? 0 : 1;
  }
  cout << (cnt <= 1 ? "Yes" : "No");

  return 0;
}