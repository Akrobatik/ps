// Title : 민식우선탐색
// Link  : https://www.acmicpc.net/problem/1376 
// Time  : 424 ms
// Memory: 54872 KB

#include <bits/stdc++.h>

using namespace std;

struct Tree {
  void Init(const vector<int>& arr) {
    int n = arr.size();
    nmax = has_single_bit((uint32_t)n) ? n : (1 << (32 - countl_zero((uint32_t)n)));
    tree.assign(nmax << 1, 0);
    maxx.assign(nmax << 1, 0);

    for (int i = 0; i < n; i++) {
      tree[i + nmax] = 1;
      maxx[i + nmax] = arr[i];
    }
    for (int i = nmax - 1; i; i--) {
      tree[i] = tree[i << 1] + tree[(i << 1) + 1];
      maxx[i] = max<int>(maxx[i << 1], maxx[(i << 1) + 1]);
    }
  }

  int Query() {
    int node = 1, sz = tree[1];
    int rem = (sz & 1) ? ((sz + 1) >> 1) : 1;
    while (node < nmax) {
      if (tree[node << 1] >= rem) {
        node <<= 1;
      } else {
        rem -= tree[node << 1];
        node = (node << 1) + 1;
      }
    }

    int res = maxx[node];
    tree[node] = maxx[node] = 0;
    while ((node >>= 1)) {
      --tree[node];
      maxx[node] = max<int>(maxx[node << 1], maxx[(node << 1) + 1]);
    }
    return res;
  }

  void Erase(int x) {
    int node = 1;
    while (node < nmax) {
      if (maxx[node << 1] >= x) {
        node <<= 1;
      } else {
        node = (node << 1) + 1;
      }
    }

    if (maxx[node] != x) return;

    tree[node] = maxx[node] = 0;
    while ((node >>= 1)) {
      --tree[node];
      maxx[node] = max<int>(maxx[node << 1], maxx[(node << 1) + 1]);
    }
  }

  bool Empty() {
    return nmax == 0 || tree[1] == 0;
  }

  int nmax;
  vector<int> tree, maxx;
};

Tree trees[100001];
vector<int> edges[100001];

void MFS(int cur) {
  cout << cur << " ";
  auto& t = trees[cur];
  while (!t.Empty()) {
    int nxt = t.Query();
    for (auto rev : edges[nxt]) trees[rev].Erase(nxt);
    MFS(nxt);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> tmp;
  tmp.reserve(m);
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u == v) continue;
    if (u > v) swap(u, v);
    tmp.push_back({u, v});
  }

  sort(tmp.begin(), tmp.end());
  tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

  for (auto [u, v] : tmp) {
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end());
    trees[i].Init(edges[i]);
  }
  for (auto e : edges[1]) trees[e].Erase(1);

  MFS(1);

  return 0;
}
