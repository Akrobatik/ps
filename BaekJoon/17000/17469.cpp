// Title : 트리의 색깔과 쿼리
// Link  : https://www.acmicpc.net/problem/17469 
// Time  : 380 ms
// Memory: 39168 KB

#include <bits/stdc++.h>

using namespace std;

int arr[100001], memo[100001];
unordered_set<int> colors[100001];

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return;
  if (colors[a].size() > colors[b].size()) swap(a, b);
  memo[a] = b;
  colors[b].insert(colors[a].begin(), colors[a].end());
  colors[a].clear();
}

int Query(int a) {
  return colors[Find(a)].size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  iota(memo, memo + n + 1, 0);
  for (int i = 2; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    colors[i].insert(x);
  }

  vector<pair<int, int>> queries(n + m - 1);
  for (auto& [op, a] : queries) cin >> op >> a;

  vector<int> ans;
  ans.reserve(m);
  for (auto [op, a] : views::reverse(queries)) {
    if (op == 1) {
      Union(a, arr[a]);
    } else {
      ans.push_back(Query(a));
    }
  }

  for (auto e : views::reverse(ans)) cout << e << "\n";

  return 0;
}
