// Title : 여행 가자
// Link  : https://www.acmicpc.net/problem/1976 
// Time  : 0 ms
// Memory: 2020 KB

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
    memo[b] = a;
  };

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      if (c == '1') Union(i, j);
    }
  }

  int x;
  cin >> x;
  int id = Find(x);
  while (--m) {
    cin >> x;
    if (id != Find(x)) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";

  return 0;
}
