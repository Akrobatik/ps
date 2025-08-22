// Title : 책 나눠주기
// Link  : https://www.acmicpc.net/problem/9576 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<pair<int, int>> arr;
  priority_queue<int, vector<int>, greater<int>> pq;

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    arr.resize(m);
    for (auto& [s, e] : arr) cin >> s >> e;
    sort(arr.begin(), arr.end());

    int cnt = 0, idx = 0;
    for (int i = 1; i <= n; i++) {
      while (!pq.empty() && pq.top() < i) pq.pop();
      while (idx < m && arr[idx].first == i) pq.push(arr[idx++].second);

      if (!pq.empty()) {
        pq.pop();
        ++cnt;
      }
    }

    cout << cnt << "\n";
  }

  return 0;
}