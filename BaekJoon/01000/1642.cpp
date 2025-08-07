// Title : 딱따구리
// Link  : https://www.acmicpc.net/problem/1642 
// Time  : 1016 ms
// Memory: 120096 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6;

vector<int> edges[kMax + 1];
int memo[kMax + 1], sz[kMax + 1], parent[kMax + 1], fact[kMax + 1];
bool check[kMax + 1];

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
  sz[a] += sz[b];
  memo[b] = a;
  return true;
}

pair<int, int> Traverse(int cur, int par) {
  parent[cur] = par;
  pair<int, int> res = {0, cur};
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    auto [cnt, id] = Traverse(nxt, cur);
    res = max<pair<int, int>>(res, {cnt + 1, id});
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k;
  cin >> n >> m >> k;

  if (k <= 2) {
    cout << "0";
    return 0;
  }

  iota(memo, memo + n + 1, 0);
  fill(sz, sz + n + 1, 1);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (!Union(u, v)) {
      cout << "0";
      return 0;
    }

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (int64_t)fact[i - 1] * i % k;
  }

  for (int i = 1; i <= n; i++) {
    check[i] = (edges[i].size() >= 2);
  }

  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (auto nxt : edges[i]) {
      cnt += check[nxt];
    }
    if (cnt > 2) {
      cout << "0\n";
      return 0;
    }
  }

  int64_t ans = 1;
  int ones = 0, twos = 0;
  for (int i = 1; i <= n; i++) {
    if (memo[i] != i) continue;

    if (edges[i].empty()) {
      ++ones;
      continue;
    }
    ++twos;

    int64_t val = 2;
    auto [_, st] = Traverse(i, 0);
    auto [cnt, en] = Traverse(st, 0);

    int cur = en, moves = 0;
    while (cur) {
      int cnt = 0;
      for (auto nxt : edges[cur]) {
        cnt += (edges[nxt].size() == 1);
      }
      moves += (cnt > 0);
      val = val * fact[cnt] % k;
      cur = parent[cur];
    }
    ans = ans * val * (sz[i] > 2 && moves >= 2 ? 2 : 1) % k;
  }
  ans = ans * fact[twos] % k;

  for (int i = 0; i < ones; i++) {
    ans = ans * (n + 1 - i) % k;
  }
  cout << ans;

  return 0;
}
