// Title : 중량제한
// Link  : https://www.acmicpc.net/problem/1939 
// Time  : 32 ms
// Memory: 3356 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<tup> arr(m);
  for (auto& [w, u, v] : arr) cin >> u >> v >> w;
  sort(arr.begin(), arr.end(), greater<tup>());

  vector<int> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Merge = [&](int a, int b) {
    a = Find(a), b = Find(b);
    memo[b] = a;
  };

  int st, en;
  cin >> st >> en;

  auto Check = [&]() {
    return Find(st) == Find(en);
  };

  for (auto [w, u, v] : arr) {
    Merge(u, v);
    if (Check()) {
      cout << w;
      break;
    }
  }

  return 0;
}
