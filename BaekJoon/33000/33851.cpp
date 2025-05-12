// Title : DAG LCA
// Link  : https://www.acmicpc.net/problem/33851 
// Time  : 16 ms
// Memory: 2204 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kInf = INT_MAX >> 1;

vector<int> rev[2001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  while (m--) {
    int u, v;
    cin >> u >> v;
    rev[v].push_back(u);
  }

  auto Traverse = [&](int st) {
    vector<int> dist(n + 1, kInf);
    queue<int> q;
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto nxt : rev[cur]) {
        if (dist[nxt] > dist[cur] + 1) {
          dist[nxt] = dist[cur] + 1;
          q.push(nxt);
        }
      }
    }
    return dist;
  };

  while (q--) {
    int u, v;
    cin >> u >> v;
    auto du = Traverse(u);
    auto dv = Traverse(v);
    int minn = kInf;
    for (int i = 1; i <= n; i++) {
      minn = min<int>(minn, max<int>(du[i], dv[i]));
    }
    cout << (minn != kInf ? minn : -1) << "\n";
  }

  return 0;
}
