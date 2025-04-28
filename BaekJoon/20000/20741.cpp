// Title : Subway Map
// Link  : https://www.acmicpc.net/problem/20741 
// Time  : 132 ms
// Memory: 28896 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int, int>;

vector<pair<int, int>> edges[100001];

int memo[100001][17];
int heights[100001];
int parents[100001][17];

void Traverse(int cur, int par, int h) {
  heights[cur] = h;
  parents[cur][0] = par;
  for (int i = 1; i < 17 && parents[par][i - 1]; i++) {
    memo[cur][i] = max<int>(memo[cur][i - 1], memo[par][i - 1]);
    par = parents[cur][i] = parents[par][i - 1];
  }

  for (auto [nxt, w] : edges[cur]) {
    if (nxt == parents[cur][0]) continue;
    memo[nxt][0] = w;
    Traverse(nxt, cur, h + 1);
  }
}

int Query(int a, int b) {
  if (heights[a] > heights[b]) swap(a, b);

  int res = 0;
  uint32_t delta = heights[b] - heights[a];
  while (delta) {
    int msb = bit_width(delta) - 1;
    res = max<int>(res, memo[b][msb]);
    b = parents[b][msb];
    delta ^= (1 << msb);
  }
  if (a == b) return res;

  for (int i = 16; i >= 0; i--) {
    if (parents[a][i] == parents[b][i]) continue;
    res = max<int>(res, memo[a][i]);
    res = max<int>(res, memo[b][i]);
    a = parents[a][i];
    b = parents[b][i];
  }
  res = max(res, memo[a][0]);
  res = max(res, memo[b][0]);
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<tup> cands(m);
  for (auto& [a, b, l, c] : cands) {
    string s;
    int x;
    cin >> a >> b >> s >> x;
    l = (s.compare("?") != 0 ? stoi(s) : -1);
    c = (x != 0);

    if (c) {
      int w = max<int>(l, 1);
      edges[a].push_back({b, w});
      edges[b].push_back({a, w});
    }
  }

  Traverse(1, 0, 0);
  for (auto [a, b, l, c] : cands) {
    if (l != -1) continue;

    if (c) {
      cout << "1\n";
    } else {
      cout << Query(a, b) << "\n";
    }
  }

  return 0;
}
