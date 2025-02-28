#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  map<int, int> m1, m2;
  ++m1[0], ++m2[0];
  int mid = n >> 1;
  for (int i = 0; i < mid; i++) {
    vector<pair<int, int>> vec(m1.begin(), m1.end());
    for (auto [e, cnt] : vec) m1[e + arr[i]] += cnt;
  }

  for (int i = mid; i < n; i++) {
    vector<pair<int, int>> vec(m2.begin(), m2.end());
    for (auto [e, cnt] : vec) m2[e + arr[i]] += cnt;
  }

  int ans = 0;
  for (auto [e, cnt] : m1) {
    ans += cnt * m2[s - e];
  }
  cout << ans - (s == 0);

  return 0;
}
