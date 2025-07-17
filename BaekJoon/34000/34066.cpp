// Title : 반짝임이 있는 곳
// Link  : https://www.acmicpc.net/problem/34066 
// Time  : 84 ms
// Memory: 5936 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  vector<tup> edges(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = {min<int>(arr[u], arr[v]), u, v};
  }
  sort(edges.begin(), edges.end(), greater<tup>());

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
    bool ok = (arr[a] == arr[b]);
    if (arr[a] > arr[b]) swap(a, b);
    memo[b] = a;
    return ok;
  };

  int cnt = n;
  for (auto [w, u, v] : edges) {
    cnt -= Union(u, v);
  }
  cout << cnt;

  return 0;
}
