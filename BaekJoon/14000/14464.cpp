// Title : 소가 길을 건너간 이유 4
// Link  : https://www.acmicpc.net/problem/14464 
// Time  : 8 ms
// Memory: 2516 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int c, n;
  cin >> c >> n;
  vector<int> arr(c);
  vector<pair<int, int>> brr(n);
  for (auto& e : arr) cin >> e;
  for (auto& [l, r] : brr) cin >> l >> r;
  sort(arr.begin(), arr.end());
  sort(brr.begin(), brr.end());

  int cnt = 0, idx = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto e : arr) {
    while (idx < n && brr[idx].first <= e) pq.push(brr[idx++].second);
    while (!pq.empty() && pq.top() < e) pq.pop();
    if (!pq.empty()) pq.pop(), ++cnt;
  }
  cout << cnt;

  return 0;
}
