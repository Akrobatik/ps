// Title : 컵라면
// Link  : https://www.acmicpc.net/problem/1781 
// Time  : 52 ms
// Memory: 5252 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [a, b] : arr) cin >> a >> b;
  sort(arr.begin(), arr.end());

  int64_t cnt = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [a, b] : arr) {
    pq.push(b);
    cnt += b;
    if (pq.size() > a) {
      cnt -= pq.top();
      pq.pop();
    }
  }
  cout << cnt;

  return 0;
}
