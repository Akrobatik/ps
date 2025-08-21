// Title : 달려라 홍준
// Link  : https://www.acmicpc.net/problem/1306 
// Time  : 216 ms
// Memory: 5932 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  m = (m - 1) << 1;

  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  deque<int> dq;
  for (int i = 0; i < m; i++) {
    while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
    dq.push_back(i);
  }

  for (int i = m; i < n; i++) {
    while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
    dq.push_back(i);
    int limit = i - m;
    while (dq.front() < limit) dq.pop_front();
    cout << arr[dq.front()] << " ";
  }

  return 0;
}