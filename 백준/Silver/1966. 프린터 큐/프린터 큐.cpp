#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      q.push({v, i});
      pq.push(v);
    }

    int cnt = 0;
    while (!q.empty()) {
      auto [v, i] = q.front();
      q.pop();

      if (v == pq.top()) {
        pq.pop();
        ++cnt;
        if (i == m) {
          cout << cnt << "\n";
          break;
        }
      } else {
        q.push({v, i});
      }
    }
  }

  return 0;
}
