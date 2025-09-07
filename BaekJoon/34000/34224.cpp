// Title : 멀지만 가까운 사이
// Link  : https://www.acmicpc.net/problem/34224 
// Time  : 508 ms
// Memory: 76896 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 5e5;

vector<pair<int, int>> edges[kMax + 1];

unordered_map<int, int> memo;

void Traverse(int cur, int par, int val) {

  ++memo[val];

  for (auto [nxt, w] : edges[cur]) {

    if (nxt == par) continue;

    Traverse(nxt, cur, val ^ w);

  }

}

int main() {

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int n;

  cin >> n;

  for (int i = 1; i < n; i++) {

    int u, v, w;

    cin >> u >> v >> w;

    edges[u].push_back({v, w});

    edges[v].push_back({u, w});

  }

  Traverse(1, 0, 0);

  int64_t ans = 0;

  for (auto [key, val] : memo) {

    ans += (int64_t)val * (val - 1) / 2;

  }

  cout << ans;

  return 0;

}

