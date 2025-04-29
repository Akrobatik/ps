// Title : 강의실 배정
// Link  : https://www.acmicpc.net/problem/11000 
// Time  : 48 ms
// Memory: 4484 KB

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

  int maxx = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  auto it = arr.begin();
  while (it != arr.end()) {
    auto [l, r] = *it++;
    while (!pq.empty() && pq.top() <= l) pq.pop();
    pq.push(r);
    maxx = max<int>(maxx, pq.size());
  }
  cout << maxx;

  return 0;
}
