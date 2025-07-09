// Title : 냅색문제
// Link  : https://www.acmicpc.net/problem/1450 
// Time  : 28 ms
// Memory: 6248 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, c;
  cin >> n >> c;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  int half = n >> 1;

  map<int, int> m1, m2;
  ++m1[0], ++m2[0];
  for (int i = 0; i < half; i++) {
    map<int, int> mp;
    int x = arr[i];
    for (auto [v, cnt] : m1) {
      mp[v] += cnt;
      if (v + x <= c) mp[v + x] += cnt;
    }
    m1.swap(mp);
  }
  for (int i = half; i < n; i++) {
    map<int, int> mp;
    int x = arr[i];
    for (auto [v, cnt] : m2) {
      mp[v] += cnt;
      if (v + x <= c) mp[v + x] += cnt;
    }
    m2.swap(mp);
  }

  vector<pair<int, int>> axr(m1.begin(), m1.end());
  vector<pair<int, int>> bxr(m2.begin(), m2.end());

  int ans = 0, sum = 0;
  for (auto [x, cnt] : bxr) sum += cnt;
  int idx = bxr.size();
  for (auto [x, cnt] : axr) {
    while (idx && x + bxr[idx - 1].first > c) sum -= bxr[--idx].second;
    ans += sum * cnt;
  }
  cout << ans;

  return 0;
}
