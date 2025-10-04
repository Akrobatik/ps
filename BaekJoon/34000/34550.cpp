// Title : 순회공연
// Link  : https://www.acmicpc.net/problem/34550 
// Time  : 40 ms
// Memory: 11372 KB

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
  vector<int8_t> cyc(n + 1, 1);

  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    cyc[i] = 0;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    int nxt = arr[cur];
    if (--deg[nxt] == 0) {
      cyc[nxt] = 0;
      q.push(nxt);
    }
  }

  vector<int> gid(n + 1, -1), order(n + 1), stk;
  vector<vector<int>> groups;
  for (int i = 1; i <= n; i++) {
    if (!cyc[i] || gid[i] != -1) continue;

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
      gid[x] = ng, order[x] = j;
    }
  }

  vector<int> root(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!cyc[i]) continue;
    root[i] = i;
    q.push(i);
  }

  for (int i = 1; !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      int cur = q.front();
      q.pop();

      int r = root[cur], gi = gid[r], ri = order[r];
      int gsz = groups[gi].size();
      for (auto nxt : g[cur]) {
        if (root[nxt]) continue;
        root[nxt] = r;
        int ord = (ri - i) % gsz;
        if (ord < 0) ord += gsz;
        int y = groups[gi][ord];
        if ((cnt[y] += cnt[nxt]) >= k) {
          cout << i + 1;
          return 0;
        }
        q.push(nxt);
      }
    }
  }
  cout << "-1";

  return 0;
}