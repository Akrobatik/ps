// Title : 트리
// Link  : https://www.acmicpc.net/problem/13306 
// Time  : 104 ms
// Memory: 9256 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> memo(n + 1), rank(n + 1);
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
    if (rank[a] == rank[b]) {
      memo[b] = a;
      ++rank[a];
    } else {
      if (rank[a] < rank[b]) swap(a, b);
      memo[b] = a;
    }
  };

  vector<int> arr(n + 1);
  for (int i = 2; i <= n; i++) {
    cin >> arr[i];
  }

  int m = n + q - 1;
  vector<tuple<int, int, int>> qr(m);
  for (auto& [cmd, a, b] : qr) {
    cin >> cmd >> a;
    if (cmd) cin >> b;
  }

  vector<int8_t> ans(q);
  for (auto [cmd, a, b] : views::reverse(qr)) {
    if (cmd == 0) {
      Union(a, arr[a]);
    } else {
      a = Find(a), b = Find(b);
      ans[--q] = (a == b ? 1 : 0);
    }
  }

  for (auto e : ans) {
    cout << (e ? "YES\n" : "NO\n");
  }

  return 0;
}