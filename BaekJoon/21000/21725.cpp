// Title : 더치페이
// Link  : https://www.acmicpc.net/problem/21725 
// Time  : 96 ms
// Memory: 14104 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<tuple<int, int, int>> qr(q);
  for (auto& [cmd, a, b] : qr) cin >> cmd >> a >> b;

  vector<int> ord = [&]() {
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
      g[i].push_back(i);
    }

    vector<int> memo(n + 1);
    iota(memo.begin(), memo.end(), 0);

    auto Find = [&](int id) {
      while (id != memo[id]) {
        int par = memo[id];
        id = memo[id] = memo[par];
      }
      return id;
    };

    auto Union = [&](int a, int b) {
      a = Find(a), b = Find(b);
      if (a == b) return;
      if (g[a].size() < g[b].size()) swap(a, b);
      memo[b] = a;
      int old = g[a].size();
      g[a].resize(old + g[b].size());
      copy(g[b].begin(), g[b].end(), g[a].begin() + old);
      g[b] = vector<int>();
    };

    for (auto [cmd, a, b] : qr) {
      if (cmd == 1) Union(a, b);
    }

    int rep = Find(1);
    vector<int> res(n + 1);
    for (int i = 0; i < n; i++) {
      res[g[rep][i]] = i;
    }
    return res;
  }();

  vector<int> memo(n + 1);
  iota(memo.begin(), memo.end(), 0);

  vector<int> minn(n + 1), maxx(n + 1);
  for (int i = 1; i <= n; i++) {
    minn[i] = maxx[i] = ord[i];
  }

  auto Find = [&](int id) {
    while (id != memo[id]) {
      int par = memo[id];
      id = memo[id] = memo[par];
    }
    return id;
  };

  auto Union = [&](int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    memo[b] = a;
    minn[a] = min<int>(minn[a], minn[b]);
    maxx[a] = max<int>(maxx[a], maxx[b]);
  };

  vector<int64_t> arr(n + 1);

  for (auto [cmd, a, b] : qr) {
    if (cmd == 1) {
      Union(a, b);
    } else {
      int id = Find(a);
      int mn = minn[id], mx = maxx[id];
      int sz = mx - mn + 1;
      int w = b / sz;
      arr[ord[a]] -= b, arr[ord[a] + 1] += b;
      arr[mn] += w, arr[mx + 1] -= w;
    }
  }

  for (int i = 0; i < n; i++) {
    arr[i + 1] += arr[i];
  }

  vector<pair<int, int64_t>> axr, bxr;
  for (int i = 1; i <= n; i++) {
    int o = ord[i];
    if (arr[o] > 0) {
      axr.push_back({i, arr[o]});
    } else if (arr[o] < 0) {
      bxr.push_back({i, -arr[o]});
    }
  }

  vector<tuple<int, int, int64_t>> ans;
  while (!axr.empty() && !bxr.empty()) {
    auto [ai, av] = axr.back();
    axr.pop_back();

    auto [bi, bv] = bxr.back();
    bxr.pop_back();

    int64_t cut = min<int64_t>(av, bv);
    ans.push_back({ai, bi, cut});
    if ((av -= cut) > 0) axr.push_back({ai, av});
    if ((bv -= cut) > 0) bxr.push_back({bi, bv});
  }

  cout << ans.size() << "\n";
  for (auto [a, b, c] : ans) cout << a << " " << b << " " << c << "\n";

  return 0;
}