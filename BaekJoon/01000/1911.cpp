// Title : 흙길 보수하기
// Link  : https://www.acmicpc.net/problem/1911 
// Time  : 4 ms
// Memory: 2220 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) cin >> l >> r;
  sort(arr.begin(), arr.end());

  int cur = 0, cnt = 0;
  for (auto [l, r] : arr) {
    l = max<int>(l, cur);
    int w = r - l;
    if (w <= 0) continue;
    int x = (w + m - 1) / m;
    cur = l + x * m;
    cnt += x;
  }
  cout << cnt;

  return 0;
}
