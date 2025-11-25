// Title : 꿈
// Link  : https://www.acmicpc.net/problem/34762 
// Time  : 16 ms
// Memory: 3156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, m;
  cin >> n >> k >> m;

  vector<int> arr(m);
  for (auto& e : arr) cin >> e;

  vector<pair<int, int>> axr;
  for (int i = 1; i < m; i++) {
    int a = arr[i - 1], b = arr[i];
    if (a + 1 < b) axr.push_back({a + 1, b - 1});
  }
  if (arr.back() != n) axr.push_back({arr.back() + 1, n});

  bool ok = true;
  for (auto [l, r] : axr) {
    ok &= (r - l + 1 > k);
  }
  cout << (ok ? "YES" : "NO");

  return 0;
}