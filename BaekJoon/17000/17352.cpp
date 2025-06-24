// Title : 여러분의 다리가 되어 드리겠습니다!
// Link  : https://www.acmicpc.net/problem/17352 
// Time  : 68 ms
// Memory: 3192 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
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
    memo[b] = a;
  };

  for (int i = 2; i < n; i++) {
    int u, v;
    cin >> u >> v;
    Union(u, v);
  }

  int par = Find(1);
  for (int i = 2; i <= n; i++) {
    if (par == Find(i)) continue;
    cout << "1 " << i;
    break;
  }

  return 0;
}
