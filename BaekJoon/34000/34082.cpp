// Title : Lv2부터 치트였던 전직 아이돌 한별이의 알록달록 트리 라이프
// Link  : https://www.acmicpc.net/problem/34082 
// Time  : 308 ms
// Memory: 46428 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[300001];

int64_t Power(int64_t n, int64_t exp, int64_t mod) {
  int64_t res = 1;
  while (exp) {
    if (exp & 1) res = res * n % mod;
    n = n * n % mod;
    exp >>= 1;
  }
  return res;
}

array<int, 4> Traverse(int cur, int par, int mod) {
  array<int, 4> res = {1, 0, 1, 0};
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    auto val = Traverse(nxt, cur, mod);
    array<int, 4> mnxt{};
    mnxt[0] = (int64_t)res[0] * (val[0] + val[1]) % mod;
    mnxt[1] = ((int64_t)res[1] * (val[0] + val[1]) + (int64_t)res[0] * val[2]) % mod;
    mnxt[2] = (int64_t)res[2] * (val[2] + val[3]) % mod;
    mnxt[3] = ((int64_t)res[3] * (val[2] + val[3]) + (int64_t)res[2] * val[0]) % mod;
    res = mnxt;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int64_t ans = Power(2, n, m);
  auto res = Traverse(1, 0, m);
  for (auto e : res) ans -= e;
  if ((ans %= m) < 0) ans += m;
  cout << ans;

  return 0;
}
