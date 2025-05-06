// Title : 어지러운 트리
// Link  : https://www.acmicpc.net/problem/25973 
// Time  : 176 ms
// Memory: 30552 KB

#include <bits/stdc++.h>

using namespace std;

int nmax;
vector<int> edges[200001];
int sz[200001];
int heights[200001], parents[200001][17];
vector<int64_t> memo;

int Traverse(int cur, int par, int h) {
  heights[cur] = h;
  parents[cur][0] = par;
  for (int i = 1; i < 17 && parents[par][i - 1]; i++) {
    par = parents[cur][i] = parents[par][i - 1];
  }

  int sum = 1;
  for (auto nxt : edges[cur]) {
    if (nxt == parents[cur][0]) continue;
    int cnt = Traverse(nxt, cur, h + 1);
    sum += cnt;
    memo[cur] -= (int64_t)cnt * cnt;
  }
  memo[cur] -= (int64_t)(nmax - sum) * (nmax - sum);
  memo[cur] >>= 1;
  return sz[cur] = sum;
}

int GetLCA(int a, int b) {
  if (heights[a] > heights[b]) swap(a, b);

  uint32_t delta = heights[b] - heights[a];
  while (delta) {
    int msb = bit_width(delta) - 1;
    b = parents[b][msb];
    delta ^= (1 << msb);
  }
  if (a == b) return a;

  int idx = bit_width((uint32_t)heights[a]);
  while (idx--) {
    if (parents[a][idx] == parents[b][idx]) continue;
    a = parents[a][idx];
    b = parents[b][idx];
  }
  return parents[a][0];
}

int64_t Excl(int r, int x) {
  if (r == x) return 0;

  int cnt;
  if (GetLCA(x, r) != x) {
    cnt = nmax - sz[x];
  } else {
    int cur = r;
    int delta = heights[r] - heights[x] - 1;
    for (int i = 0; delta; i++) {
      if (delta & 1) cur = parents[cur][i];
      delta >>= 1;
    }
    cnt = sz[cur];
  }
  return (int64_t)cnt * (nmax - cnt);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  nmax = n;
  memo.assign(n + 1, (int64_t)n * n - 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  Traverse(1, 0, 0);

  int r = 1;
  while (q--) {
    int cmd, x;
    cin >> cmd >> x;
    if (cmd == 1) {
      r = x;
    } else {
      cout << memo[x] - Excl(r, x) << "\n";
    }
  }

  return 0;
}