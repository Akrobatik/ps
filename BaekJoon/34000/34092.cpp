// Title : 자율 주행 프로그램 개발
// Link  : https://www.acmicpc.net/problem/34092 
// Time  : 372 ms
// Memory: 27540 KB

#include <bits/stdc++.h>

using namespace std;

struct Node {
  Node() : l(0), r(0), p(0) {}

  int l, r, p;
};

vector<Node> nodes;
vector<int> depth;
vector<vector<int>> layers;
vector<bool> mask;
vector<int> head, pend;

void Build(int cur, int d) {
  depth[cur] = d;
  layers[d].push_back(cur);
  if (nodes[cur].l) Build(nodes[cur].l, d + 1);
  if (nodes[cur].r) Build(nodes[cur].r, d + 1);
}

int GetLCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  while (depth[u] != depth[v]) u = nodes[u].p;
  while (u != v) u = nodes[u].p, v = nodes[v].p;
  return u;
}

int GetMid(int u, int v, int r) {
  if (depth[u] < depth[v]) swap(u, v);
  int d = (depth[u] + depth[v] - (depth[r] << 1)) >> 1;
  while (d--) u = nodes[u].p;
  return u;
}

string GetPath(int u, int v) {
  string s;
  while (u != v) {
    int p = nodes[u].p;
    s.push_back(nodes[p].l == u ? 'L' : 'R');
    u = p;
  }
  reverse(s.begin(), s.end());
  return s;
}

int MoveRev(int u, string_view sv) {
  for (auto c : views::reverse(sv)) {
    int p = nodes[u].p;
    if (c == 'L') {
      u = (nodes[p].l == u ? p : 0);
    } else {
      u = (nodes[p].r == u ? p : 0);
    }
    if (u == 0) break;
  }
  return u;
}

int MoveRev(int u, char c) {
  if (c == 'X') return 0;

  int p = nodes[u].p;
  if (c == 'L') {
    u = (nodes[p].l == u ? p : 0);
  } else {
    u = (nodes[p].r == u ? p : 0);
  }
  return u;
}

void SetHead(int cur, int h, int p) {
  if (mask[cur]) h = cur, p = pend[cur];
  head[cur] = h;
  pend[cur] = p;
  if (nodes[cur].l) SetHead(nodes[cur].l, h, p + 1);
  if (nodes[cur].r) SetHead(nodes[cur].r, h, p + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> memo, mnxt;

  int t;
  cin >> t;
  while (t--) {
    int n, st, en;
    cin >> n >> st >> en;
    nodes.assign(n + 1, Node());
    depth.assign(n + 1, 0);
    layers.assign(n, vector<int>());
    for (int i = 1; i <= n; i++) {
      int l, r;
      cin >> l >> r;
      nodes[i].l = l;
      nodes[i].r = r;
      if (l) nodes[l].p = i;
      if (r) nodes[r].p = i;
    }
    Build(1, 0);

    if ((depth[st] + depth[en]) & 1) {
      cout << "ERROR\n";
      continue;
    }

    int lca = GetLCA(st, en);
    int mid = GetMid(st, en, lca);
    int sd = (depth[st] + depth[en]) >> 1;

    string el = GetPath(en, 1);
    string_view sv(el);
    int ns = sv.size();

    mask.assign(n + 1, false);
    head.assign(n + 1, 0);
    pend.assign(n + 1, 0);

    int cur = mid;
    for (int i = 0; cur; i++) {
      mask[cur] = true;
      pend[cur] = i;
      cur = nodes[cur].p;
    }
    SetHead(1, 0, 0);

    int suf, m;
    if (depth[st] >= depth[en]) {
      suf = depth[en] - depth[lca];
      m = mid;
    } else {
      suf = depth[en] - depth[mid];
      m = lca;
    }

    auto sub = sv.substr(ns - suf);

    memo.clear();
    for (auto e : layers[sd]) {
      int u = MoveRev(e, sub);
      if (u == 0) continue;
      int p = pend[head[e]];
      if (!mask[u]) p = max<int>(p, pend[u] - p);
      memo.push_back({u, p});
    }

    while (m) {
      if (memo.empty()) {
        m = 0;
        break;
      }

      bool ok = false;

      int si = ns - (++suf);
      char dir = (si >= 0 ? sv[si] : 'X');
      mnxt.clear();
      for (auto [e, p] : memo) {
        if (e == m && p <= 0) {
          ok = true;
          break;
        }
        int u = MoveRev(e, dir);
        if (u) mnxt.push_back({u, p - 1});
      }

      if (ok) break;

      m = nodes[m].p;
      swap(memo, mnxt);
    }

    if (m) {
      int up = depth[st] - depth[m];
      for (int i = 0; i < up; i++) cout << "B";
      cout << sv.substr(ns - suf + 1) << "\n";
    } else {
      cout << "ERROR\n";
    }
  }

  return 0;
}
