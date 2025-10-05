// Title : 즐거운 회의
// Link  : https://www.acmicpc.net/problem/31997 
// Time  : 88 ms
// Memory: 4368 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, t;
  cin >> n >> m >> t;

  vector<pair<int, int>> lr(n);
  for (auto& [l, r] : lr) cin >> l >> r;

  vector<int> arr(t + 1);
  while (m--) {
    int u, v;
    cin >> u >> v, --u, --v;
    auto [ul, ur] = lr[u];
    auto [vl, vr] = lr[v];
    int s = max<int>(ul, vl), e = min<int>(ur, vr);
    if (s < e) ++arr[s], --arr[e];
  }

  for (int i = 0; i < t; i++) {
    cout << arr[i] << "\n";
    arr[i + 1] += arr[i];
  }

  return 0;
}