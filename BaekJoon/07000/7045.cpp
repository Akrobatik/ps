// Title : Tree Cutting
// Link  : https://www.acmicpc.net/problem/7045 
// Time  : 0 ms
// Memory: 2660 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[10001];
bool ok[10001];
int n, half;

int Traverse(int cur, int par) {
  int sum = 1;
  auto& o = ok[cur];
  o = true;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    int cnt = Traverse(nxt, cur);
    sum += cnt;
    if (cnt > half) o = false;
  }
  int rem = n - sum;
  if (rem > half) o = false;
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  half = n >> 1;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  Traverse(1, 0);

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) continue;
    cout << i << "\n";
    ++cnt;
  }

  if (cnt == 0) cout << "NONE";

  return 0;
}
