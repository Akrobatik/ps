// Title : 브레인롯 챔피언십
// Link  : https://www.acmicpc.net/problem/34560 
// Time  : 64 ms
// Memory: 31516 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<string, int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (auto& [s, a, b, c] : arr) cin >> s >> a >> b >> c;
  sort(arr.begin(), arr.end());

  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    auto& [is, ia, ib, ic] = arr[i];
    for (int j = i + 1; j < n; j++) {
      auto& [js, ja, jb, jc] = arr[j];
      int iv = (ia >= ja) + (ib >= jb) + (ic >= jc);
      int jv = (ja >= ia) + (jb >= ib) + (jc >= ic);
      if (iv > jv) g[j].push_back(i);
      if (iv < jv) g[i].push_back(j);
    }
  }

  vector<int> memo(n);

  auto DFS = [&](this auto&& self, int cur) {
    memo[cur] = 1;
    for (auto nxt : g[cur]) {
      if (memo[nxt] == 1) return true;
      if (memo[nxt] == 0 && self(nxt)) return true;
    }
    memo[cur] = -1;
    return false;
  };

  bool cycle = false;
  for (int i = 0; !cycle && i < n; i++) {
    if (memo[i]) continue;
    cycle = DFS(i);
  }

  if (cycle) {
    cout << "Paradoxe Absurdo";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (g[i].empty()) cout << get<0>(arr[i]) << "\n";
  }

  return 0;
}