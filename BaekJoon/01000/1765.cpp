// Title : 닭싸움 팀 정하기
// Link  : https://www.acmicpc.net/problem/1765 
// Time  : 4 ms
// Memory: 2236 KB

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

  DSU dsu;
  dsu.Init(n + 1);

  vector<vector<int>> g(n + 1);
  while (m--) {
    char cmd;
    int a, b;
    cin >> cmd >> a >> b;
    if (cmd == 'F') {
      dsu.Union(a, b);
    } else {
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }

  for (int i = 1; i <= n; i++) {
    [&](this auto&& self, int cur, int par, int depth) -> void {
      if (depth == 2) {
        dsu.Union(i, cur);
        return;
      }

      for (auto nxt : g[cur]) {
        if (nxt == par) continue;
        self(nxt, cur, depth + 1);
      }
    }(i, 0, 0);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (i == dsu.Find(i));
  }
  cout << cnt;

  return 0;
}