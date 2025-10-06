// Title : 불우이웃돕기
// Link  : https://www.acmicpc.net/problem/1414 
// Time  : 0 ms
// Memory: 2156 KB

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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '0') continue;
      int d = (c >= 'a' ? c - 'a' + 1 : c - 'A' + 27);
      adj.push_back({d, i, j});
    }
  }
  sort(adj.begin(), adj.end());

  DSU dsu;
  dsu.Init(n);

  int64_t rem = n - 1, sum = 0;
  for (auto [w, u, v] : adj) {
    sum += w;
    if (dsu.Union(u, v)) sum -= w, --rem;
  }

  cout << (rem ? -1 : sum);

  return 0;
}