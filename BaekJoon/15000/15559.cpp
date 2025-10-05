// Title : 내 선물을 받아줘
// Link  : https://www.acmicpc.net/problem/15559 
// Time  : 52 ms
// Memory: 35612 KB

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

  vector<string> board(n);
  for (auto& s : board) cin >> s;

  DSU dsu;
  dsu.Init(n * m);

  auto Idx = [&](int y, int x) {
    return y * m + x;
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int dy, dx;
      switch (board[i][j]) {
        case 'N': {
          dy = -1, dx = 0;
        } break;
        case 'W': {
          dy = 0, dx = -1;
        } break;
        case 'E': {
          dy = 0, dx = 1;
        } break;
        case 'S': {
          dy = 1, dx = 0;
        } break;
      }

      dsu.Union(Idx(i, j), Idx(i + dy, j + dx));
    }
  }

  int cnt = 0;
  for (int i = 0; i < n * m; i++) {
    if (dsu.Find(i) != i) continue;
    ++cnt;
  }
  cout << cnt;

  return 0;
}