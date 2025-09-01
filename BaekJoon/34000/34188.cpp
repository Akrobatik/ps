// Title : Tri-Tree XOR
// Link  : https://www.acmicpc.net/problem/34188 
// Time  : 292 ms
// Memory: 36292 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 3e5;

vector<pair<int, int>> ans;
vector<int> edges[kMax + 1];

int Traverse(int cur, int par) {
  int rem = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;

    int res = Traverse(nxt, cur);
    if (res == 0) continue;

    if (rem) {
      ans.push_back({rem, cur});
      ans.push_back({rem, res});
      rem = 0;
    } else {
      rem = res;
    }
  }

  if (rem) {
    ans.push_back({rem, cur});
    ans.push_back({rem, par});
    return 0;
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (~n & 1) {
    cout << "NO";
    return 0;
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  ans.reserve(n - 1);
  Traverse(1, 0);

  cout << "YES\n";
  for (auto [u, v] : ans) {
    cout << u << " " << v << "\n";
  }

  return 0;
}
