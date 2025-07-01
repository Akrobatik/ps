// Title : Split the SSHS 3
// Link  : https://www.acmicpc.net/problem/31740 
// Time  : 60 ms
// Memory: 15616 KB

#include <bits/stdc++.h>

using namespace std;

vector<int> edges[100001];
int weights[100001];
int all, minn, ans[2];

int Traverse(int cur, int par) {
  int sum = 0;
  for (auto nxt : edges[cur]) {
    if (nxt == par) continue;
    int w = Traverse(nxt, cur);
    sum += w;
    int val = abs(all - w * 2);
    if (minn > val) minn = val, ans[0] = cur, ans[1] = nxt;
  }
  return sum + weights[cur];
}

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

  for (int i = 1; i <= n; i++) {
    cin >> weights[i];
    all += weights[i];
  }

  minn = INT_MAX;
  Traverse(1, 0);
  cout << minn << "\n"
       << ans[0] << " " << ans[1];

  return 0;
}
