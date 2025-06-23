// Title : 우주신과의 교감
// Link  : https://www.acmicpc.net/problem/1774 
// Time  : 16 ms
// Memory: 14464 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int, int>;

int memo[1001];

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

bool Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return false;
  memo[b] = a;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  iota(memo, memo + n + 1, 0);
  vector<pair<int, int>> coords(n);
  for (auto& [y, x] : coords) cin >> x >> y;

  int cnt = 1;
  while (m--) {
    int u, v;
    cin >> u >> v;
    cnt += Union(u, v);
  }

  priority_queue<tup, vector<tup>, greater<tup>> pq;
  for (int i = 1; i <= n; i++) {
    auto [iy, ix] = coords[i - 1];
    for (int j = i + 1; j <= n; j++) {
      auto [jy, jx] = coords[j - 1];
      int64_t dy = iy - jy, dx = ix - jx;
      int64_t d = dy * dy + dx * dx;
      pq.push({d, i, j});
    }
  }

  double sum = 0.0;
  while (cnt < n) {
    auto [d, u, v] = pq.top();
    pq.pop();

    if (Union(u, v)) {
      sum += sqrt((double)d);
      ++cnt;
    }
  }

  sum = round(sum * 100.0) / 100.0;
  cout << setprecision(2) << fixed << sum;

  return 0;
}
