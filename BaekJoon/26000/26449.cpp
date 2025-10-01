// Title : Harvest
// Link  : https://www.acmicpc.net/problem/26449 
// Time  : 36 ms
// Memory: 2940 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) cin >> l >> r;

  sort(arr.begin(), arr.end());

  int k;
  cin >> k;
  vector<int> memo;
  int idx = 0, cnt = 0;
  while (k--) {
    int x;
    cin >> x;
    while (idx < n && arr[idx].first <= x) memo.push_back(arr[idx++].second);
    while (!memo.empty()) {
      int y = memo.back();
      memo.pop_back();
      cnt += (y >= x);
    }
  }
  cout << cnt;

  return 0;
}