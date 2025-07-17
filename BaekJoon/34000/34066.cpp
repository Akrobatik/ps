// Title : 반짝임이 있는 곳
// Link  : https://www.acmicpc.net/problem/34066 
// Time  : 128 ms
// Memory: 16428 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[200001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  vector<int> sorted(n);
  iota(sorted.begin(), sorted.end(), 1);
  sort(sorted.begin(), sorted.end(), [&](int lhs, int rhs) {
    return arr[lhs] > arr[rhs];
  });

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

  int cnt = 0, idx = 0;
  vector<bool> check(n + 1), tmp(n + 1);
  while (idx < n) {
    int nxt = idx;
    while (nxt < n && arr[sorted[idx]] == arr[sorted[nxt]]) check[sorted[nxt++]] = true;
    for (int i = idx; i < nxt; i++) {
      int u = sorted[i];
      for (auto v : edges[u]) {
        if (!check[v]) continue;
        Union(u, v);
      }
    }
    for (int i = idx; i < nxt; i++) {
      int id = Find(sorted[i]);
      if (tmp[id]) continue;
      tmp[id] = true;
      ++cnt;
    }
    for (int i = idx; i < nxt; i++) {
      int id = Find(sorted[i]);
      tmp[id] = false;
    }
    idx = nxt;
  }
  cout << cnt;

  return 0;
}
