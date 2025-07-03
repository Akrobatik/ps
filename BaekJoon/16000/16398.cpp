// Title : 행성 연결
// Link  : https://www.acmicpc.net/problem/16398 
// Time  : 152 ms
// Memory: 7880 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> memo(n);
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

  vector<tup> arr;
  arr.reserve((n * (n - 1)) >> 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (i >= j) continue;
      arr.push_back({x, i, j});
    }
  }
  sort(arr.begin(), arr.end());

  int64_t sum = 0;
  for (int i = 0, r = n - 1; r; i++) {
    auto [x, a, b] = arr[i];
    if (!Union(a, b)) continue;
    --r, sum += x;
  }
  cout << sum;

  return 0;
}
