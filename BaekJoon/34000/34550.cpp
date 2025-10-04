// Title : 순회공연
// Link  : https://www.acmicpc.net/problem/34550 
// Time  : 56 ms
// Memory: 12440 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    arr[i] = x;
    g[x].push_back(i);
  }

  vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (++cnt[x] >= k) {
      cout << "1";
      return 0;
    }
  }

  vector<int> deg(n + 1);
  for (int i = 1; i <= n; i++) {
    ++deg[arr[i]];
  }

  queue<int> q;
  vector<bool> cyc(n + 1, true);

  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    cyc[i] = false;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int nxt = arr[cur];
    if (--deg[nxt] == 0) {
      cyc[nxt] = false;
      q.push(nxt);
    }
  }

  vector<int> stk;
  vector<vector<int>> groups;
  vector<pair<int, int>> memo(n + 1, {-1, -1});
  for (int i = 1; i <= n; i++) {
    if (!cyc[i] || memo[i].first != -1) continue;

    stk.clear();
    int cur = i;
    do {
      stk.push_back(cur);
      cur = arr[cur];
    } while (cur != i);

    int ns = stk.size();
    int ng = groups.size();
    groups.push_back(stk);

    for (int j = 0; j < ns; j++) {
      int x = stk[j];
      memo[x] = {ng, j};
    }
  }

  auto Get = [&](int r, int t) {
    auto [gi, ord] = memo[r];
    int sz = groups[gi].size();
    ord -= t;
    if ((ord %= sz) < 0) ord += sz;
    return groups[gi][ord];
  };

  vector<int> root(n + 1);
  vector<tuple<int, int, int>> brr;
  for (int i = 1; i <= n; i++) {
    if (!cyc[i]) continue;
    root[i] = i;
    if (cnt[i]) brr.push_back({0, i, cnt[i]});
    q.push(i);
  }

  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      for (auto nxt : g[cur]) {
        if (root[nxt]) continue;
        root[nxt] = root[cur];
        if (cnt[nxt]) brr.push_back({i, Get(root[nxt], i), cnt[nxt]});
        q.push(nxt);
      }
    }
  }

  vector<int> sum(n + 1);
  for (auto [t, i, c] : brr) {
    if ((sum[i] += c) >= k) {
      cout << t + 1;
      return 0;
    }
  }
  cout << "-1";

  return 0;
}