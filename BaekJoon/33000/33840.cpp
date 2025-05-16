// Title : 센트로이드 트리와 복원
// Link  : https://www.acmicpc.net/problem/33840 
// Time  : 104 ms
// Memory: 9724 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100000];
int sz[100000];
bool used[100000];

int Traverse(int cur, int par) {
  auto& res = sz[cur];
  res = 1;
  for (auto nxt : edges[cur]) {
    if (nxt == par || used[nxt]) continue;
    res += Traverse(nxt, cur);
  }
  return res;
}

int Find(int cur) {
  int par = 0, half = sz[cur] >> 1;
  for (;;) {
    bool ok = true;
    for (auto nxt : edges[cur]) {
      if (nxt == par || used[nxt] || sz[nxt] <= half) continue;
      par = cur;
      cur = nxt;
      ok = false;
      break;
    }
    if (ok) break;
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> org, dst;
  org.reserve(n - 1), dst.reserve(n - 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
    if (u > v) swap(u, v);
    org.push_back({u, v});
  }

  function<void(int, int)> Make = [&](int cur, int par) {
    Traverse(cur, par);
    int cent = Find(cur);
    if (par) dst.push_back({min<int>(par, cent), max<int>(par, cent)});
    used[cent] = true;
    for (auto nxt : edges[cent]) {
      if (!used[nxt]) Make(nxt, cent);
    }
  };

  Make(1, 0);

  sort(org.begin(), org.end());
  sort(dst.begin(), dst.end());

  bool ok = true;
  for (int i = 0; ok && i < org.size(); i++) {
    ok = (org[i].first == dst[i].first && org[i].second == dst[i].second);
  }

  if (ok) {
    for (auto [u, v] : dst) cout << u << " " << v << "\n";
  } else {
    cout << "-1";
  }

  return 0;
}