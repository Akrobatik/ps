// Title : StackExplosion
// Link  : https://www.acmicpc.net/problem/35482 
// Time  : 232 ms
// Memory: 9840 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);
  for (auto& pr : arr) cin >> pr.first;
  for (auto& pr : arr) cin >> pr.second;

  sort(arr.begin(), arr.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.first - lhs.second < rhs.first - rhs.second;
  });

  int idx = 0, cnt = 0;
  int64_t add = 0;
  while (idx < n && arr[idx].first < add + arr[idx].second) {
    int nxt = idx;
    int64_t cadd = 0;
    while (nxt < n && arr[nxt].first < add + arr[nxt].second) {
      cadd += (add + arr[nxt++].second) >> 1;
      ++cnt;
    }

    idx = nxt;
    add += cadd;
  }
  cout << cnt;

  return 0;
}