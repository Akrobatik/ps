// Title : Distance Multiplication Maximization
// Link  : https://www.acmicpc.net/problem/34062 
// Time  : 3120 ms
// Memory: 29436 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[300001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int st, en;
  queue<int> q;
  vector<bool> visited(n + 1);

  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    st = q.front();
    q.pop();

    for (auto nxt : edges[st]) {
      if (visited[nxt]) continue;
      visited[nxt] = true;
      q.push(nxt);
    }
  }

  visited.assign(n + 1, false);
  vector<int> parents(n + 1);

  q.push(st);
  visited[st] = true;
  while (!q.empty()) {
    en = q.front();
    q.pop();

    for (auto nxt : edges[en]) {
      if (visited[nxt]) continue;
      visited[nxt] = true;
      parents[nxt] = en;
      q.push(nxt);
    }
  }

  vector<int> arr;
  int cur = en;
  do arr.push_back(cur);
  while (cur = parents[cur]);

  visited.assign(n + 1, false);
  for (auto e : arr) visited[e] = true;

  int na = arr.size();
  vector<int> maxd(na);
  vector<int> head(n + 1), dist(n + 1);
  for (int i = 0; i < na; i++) {
    q.push(arr[i]);
    for (int j = 0; !q.empty(); j++) {
      int nq = q.size();
      while (nq--) {
        int u = q.front();
        q.pop();

        head[u] = i;
        dist[u] = j;
        for (auto nxt : edges[u]) {
          if (visited[nxt]) continue;
          visited[nxt] = true;
          q.push(nxt);
        }
      }
      maxd[i] = j;
    }
  }

  --na;
  int l = na >> 1, r = na - l;
  while (l && l != maxd[l]) --l;
  while (r < na && na - r != maxd[r]) ++r;

  map<int, vector<int>> mp;
  for (int i = l + 1; i < r; i++) mp[maxd[i]].push_back(i);

  vector<pair<int, vector<int>>> memo;
  for (auto& [d, v] : mp) {
    auto& vec = memo.emplace_back();
    vec.first = d;
    vec.second = move(v);
  }

  auto GetDist = [&](int uh, int ud, int vh, int vd) -> int64_t {
    return abs(uh - vh) + ud + vd;
  };

  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (head[u] > head[v]) swap(u, v);
    int uh = head[u], ud = dist[u];
    int vh = head[v], vd = dist[v];

    auto Calc = [&](int h, int d) {
      return GetDist(h, d, uh, ud) * GetDist(h, d, vh, vd);
    };

    int64_t maxx = max<int64_t>({Calc(0, 0), Calc(na, 0), Calc(l, maxd[l]), Calc(r, maxd[r])});

    if (r - l >= 2 && vh - uh >= 2 && uh + 1 <= r - 1 && l + 1 <= vh - 1) {
      int pl = max<int>(l, uh) + 1, pr = min<int>(r, vh) - 1;
      int pv = (uh + vh + vd - ud - 1) >> 1;
      for (auto& [d, hs] : memo) {
        auto rit = upper_bound(hs.begin(), hs.end(), pv);
        auto lit = (rit != hs.begin() ? rit - 1 : hs.end());
        for (auto& it : {lit, rit}) {
          if (it == hs.end()) continue;
          int h = *it;
          if (pl <= h && h <= pr) maxx = max<int64_t>(maxx, Calc(h, d));
        }
      }
    }
    cout << maxx << "\n";
  }

  return 0;
}
