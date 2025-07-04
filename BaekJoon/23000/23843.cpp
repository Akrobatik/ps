// Title : 콘센트
// Link  : https://www.acmicpc.net/problem/23843 
// Time  : 0 ms
// Memory: 2176 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end(), greater<int>());

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < m; i++) pq.push(0);
  for (int i = 0; i < n; i++) {
    auto x = pq.top();
    pq.pop();
    pq.push(x + arr[i]);
  }

  int x;
  while (!pq.empty()) x = pq.top(), pq.pop();
  cout << x;

  return 0;
}
