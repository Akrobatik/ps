// Title : 강의실
// Link  : https://www.acmicpc.net/problem/1374 
// Time  : 48 ms
// Memory: 3704 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto& [b, e] : arr) cin >> b >> b >> e;
  sort(arr.begin(), arr.end());

  int maxx = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [b, e] : arr) {
    while (!pq.empty() && pq.top() <= b) pq.pop();
    pq.push(e);
    maxx = max<int>(maxx, pq.size());
  }
  cout << maxx;

  return 0;
}
