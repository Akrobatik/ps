// Title : 물대기
// Link  : https://www.acmicpc.net/problem/1368 
// Time  : 12 ms
// Memory: 3304 KB

#include <bits/stdc++.h>

using namespace std;

// https://github.com/Akrobatik/ps/blob/main/template/dsu.cpp
struct DSU {
  void Init(int n) {
    memo.resize(n);
    iota(memo.begin(), memo.end(), 0);
    sz.assign(n, 1);
    stk.clear();
  }

  int Find(int id) {
    while (id != memo[id]) id = memo[id];
    return id;
  }

  bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    stk.push_back({a, b, sz[a], memo[b]});
    memo[b] = a;
    sz[a] += sz[b];
    return true;
  }

  int Checkpoint() {
    return stk.size();
  }

  void Rollback(int cnt) {
    while (stk.size() > cnt) {
      auto [a, b, sa, mb] = stk.back();
      stk.pop_back();
      memo[b] = mb;
      sz[a] = sa;
    }
  }

 private:
  vector<int> memo, sz;
  vector<tuple<int, int, int, int>> stk;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<int, int, int>> adj;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    adj.push_back({w, 0, i});
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int w;
      cin >> w;
      if (i < j) adj.push_back({w, i, j});
    }
  }
  sort(adj.begin(), adj.end());

  DSU dsu;
  dsu.Init(n + 1);

  int64_t sum = 0;
  for (auto [w, u, v] : adj) {
    if (dsu.Union(u, v)) sum += w;
  }
  cout << sum;

  return 0;
}