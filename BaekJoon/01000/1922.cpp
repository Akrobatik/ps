// Title : 네트워크 연결
// Link  : https://www.acmicpc.net/problem/1922 
// Time  : 32 ms
// Memory: 3328 KB

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

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> adj(m);
  for (auto& [w, u, v] : adj) cin >> u >> v >> w;
  sort(adj.begin(), adj.end());

  int64_t sum = 0;
  DSU dsu;
  dsu.Init(n + 1);
  for (auto [w, u, v] : adj) {
    if (dsu.Union(u, v)) sum += w;
  }
  cout << sum;

  return 0;
}