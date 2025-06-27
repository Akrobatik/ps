// Title : 미확인 도착지
// Link  : https://www.acmicpc.net/problem/9370 
// Time  : 28 ms
// Memory: 4468 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = 1e9 + 1;

vector<vector<pair<int, int>>> edges;
vector<int> cands, da, db;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Calc(int st, vector<int>& dist) {
  auto Push = [&](int x, int d) {
    if (dist[x] <= d) return;
    dist[x] = d;
    pq.push({d, x});
  };

  Push(st, 0);
  while (!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();

    if (dist[cur] != d) continue;

    for (auto [nxt, dd] : edges[cur]) {
      Push(nxt, d + dd);
    }
  }
}

void Solve() {
  int n, m, t, s, g, h;
  cin >> n >> m >> t >> s >> g >> h;
  if (g > h) swap(g, h);

  edges.assign(n + 1, vector<pair<int, int>>());
  da.assign(n + 1, kInf);
  db.assign(n + 1, kInf);

  int gh = kInf;
  while (m--) {
    int a, b, d;
    cin >> a >> b >> d;
    if (a > b) swap(a, b);
    edges[a].push_back({b, d});
    edges[b].push_back({a, d});
    if (a == g && b == h) gh = min<int>(gh, d);
  }

  Calc(s, da);
  if (da[g] > da[h]) swap(g, h);
  Calc(h, db);

  cands.resize(t);
  for (auto& e : cands) cin >> e;
  sort(cands.begin(), cands.end());
  for (auto e : cands) {
    if (da[e] == da[g] + db[e] + gh) {
      cout << e << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) Solve();

  return 0;
}
