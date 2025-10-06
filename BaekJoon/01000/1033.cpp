// Title : 칵테일
// Link  : https://www.acmicpc.net/problem/1033 
// Time  : 0 ms
// Memory: 2088 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int64_t GCD(int64_t a, int64_t b) {
  while (b) a %= b, swap(a, b);
  return a;
}

int64_t LCM(int64_t a, int64_t b) {
  return a * b / GCD(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<tup>> g(n);
  for (int i = 1; i < n; i++) {
    int a, b, p, q;
    cin >> a >> b >> p >> q;
    g[a].push_back({b, q, p});
    g[b].push_back({a, p, q});
  }

  vector<pair<int64_t, int64_t>> memo(n);
  memo[0] = {1, 1};

  [&](this auto&& self, int cur, int par) -> void {
    auto [cp, cq] = memo[cur];
    for (auto [nxt, p, q] : g[cur]) {
      if (nxt == par) continue;
      memo[nxt] = {cp * p, cq * q};
      self(nxt, cur);
    }
  }(0, -1);

  int64_t oq = 1;
  for (auto [p, q] : memo) {
    oq = LCM(oq, q);
  }

  int64_t op = 0;
  for (auto& [p, q] : memo) {
    p *= oq / q;
    op = GCD(op, p);
  }

  for (auto [p, q] : memo) {
    cout << p / op << " ";
  }

  return 0;
}