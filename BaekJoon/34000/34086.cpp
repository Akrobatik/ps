// Title : 트리 이사
// Link  : https://www.acmicpc.net/problem/34086 
// Time  : 200 ms
// Memory: 18080 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[2001], edges2[2001];
int coords[2001][2001];
int memo[2001], val[2001], parents[2001];
int dir[1000], color[2001];
bool locked[1000];

int Find(int id) {
  while (id != memo[id]) {
    int par = memo[id];
    id = memo[id] = memo[par];
  }
  return id;
}

void Union(int a, int b) {
  a = Find(a), b = Find(b);
  if (a == b) return;
  edges[a].insert(edges[a].end(), edges[b].begin(), edges[b].end());
  edges[b] = vector<int>();
  memo[b] = a;
}

void Compress() {
  bool visited[2001] = {};
  queue<int> q;
  int st = Find(1);
  q.push(st);
  visited[st];
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto& nxt : edges[cur]) nxt = Find(nxt);
    sort(edges[cur].begin(), edges[cur].end(), [&](int lhs, int rhs) {
      int lv = (lhs == cur ? INT_MAX : lhs), rv = (rhs == cur ? INT_MAX : rhs);
      return lv < rv;
    });
    edges[cur].erase(unique(edges[cur].begin(), edges[cur].end()), edges[cur].end());
    while (!edges[cur].empty() && edges[cur].back() == cur) edges[cur].pop_back();

    for (auto nxt : edges[cur]) {
      if (visited[nxt]) continue;
      visited[nxt] = true;
      q.push(nxt);
    }
  }
}

int Calc(int cur, int par) {
  int sum = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    sum += Calc(nxt, cur);
  }
  return val[cur] = max<int>(sum, 1);
}

int GetHeavy(int st) {
  Calc(st, 0);
  int cur = st, par = 0;
  for (;;) {
    parents[cur] = par;
    bool none = true;
    int maxx = 0, mi;
    for (auto nxt : edges[cur]) {
      if (nxt == par) continue;
      none = false;
      if (maxx < val[nxt]) maxx = val[nxt], mi = nxt;
    }
    if (none) break;
    par = cur, cur = mi;
  }
  return cur;
}

int Rebuild(int u, int dim) {
  int v = GetHeavy(u);
  int cur = v;
  while (cur) {
    Union(u, cur);
    color[cur] = min<int>(color[cur], dim);
    cur = parents[cur];
  }
  Compress();
  return v;
}

void SetCoord(int cur, int par, int md, int dim) {
  for (int i = 0; i < md; i++) coords[cur][i] = coords[par][i];
  coords[cur][dim] += dir[dim];

  for (auto nxt : edges2[cur]) {
    if (nxt == par) continue;

    int ndim = color[nxt];
    if (!locked[ndim]) {
      locked[ndim] = true;
      dir[ndim] = (dir[ndim] == 0 ? 1 : -1);
      SetCoord(nxt, cur, md, ndim);
      locked[ndim] = false;
    } else {
      SetCoord(nxt, cur, md, ndim);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  memset(color, 0x7f, sizeof(int) * (n + 1));
  iota(memo, memo + n + 1, 0);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
    edges2[u].push_back(v);
    edges2[v].push_back(u);
  }

  vector<int> leafs;
  for (int i = 1; i <= n; i++) {
    if (edges[i].size() != 1) continue;
    leafs.push_back(i);
  }

  int nl = leafs.size();
  int md = 0, root = 0;
  bool used[2001] = {};
  for (int i = 0; i < nl; i++) {
    if (used[leafs[i]]) continue;
    int v = Rebuild(leafs[i], md++);
    used[leafs[i]] = used[v] = true;
    if (root == 0) root = leafs[i];
  }
  SetCoord(root, 0, md, 0);

  cout << md << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < md; j++) {
      cout << coords[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
