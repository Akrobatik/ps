// Title : 친구비
// Link  : https://www.acmicpc.net/problem/16562 
// Time  : 4 ms
// Memory: 2180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = id;
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (arr[a] > arr[b]) swap(a, b);
    memo[b] = a;
  };

  while (m--) {
    int u, v;
    cin >> u >> v;
    Union(u, v);
  }

  int64_t sum = 0;
  for (int i = 1; i <= n; i++) {
    if (memo[i] != i) continue;
    sum += arr[i];
  }

  if (sum <= k) {
    cout << sum;
  } else {
    cout << "Oh no";
  }

  return 0;
}