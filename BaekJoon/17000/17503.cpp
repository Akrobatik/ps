// Title : 맥주 축제
// Link  : https://www.acmicpc.net/problem/17503 
// Time  : 68 ms
// Memory: 5252 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> arr(k);
  for (auto& [lv, x] : arr) cin >> x >> lv;
  sort(arr.begin(), arr.end());

  int64_t sum = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [lv, x] : arr) {
    pq.push(x);
    sum += x;
    if (pq.size() == n + 1) sum -= pq.top(), pq.pop();
    if (pq.size() == n && sum >= m) {
      cout << lv;
      return 0;
    }
  }
  cout << "-1";

  return 0;
}
