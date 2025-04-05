// Title : 철로
// Link  : https://www.acmicpc.net/problem/13334
// Time  : 36 ms
// Memory: 3680 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> lines(n);
  for (int i = 0; i < n; i++) {
    cin >> lines[i].first >> lines[i].second;
    if (lines[i].first > lines[i].second) swap(lines[i].first, lines[i].second);
  }
  sort(lines.begin(), lines.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second != rhs.second ? lhs.second < rhs.second : lhs.first < rhs.first;
  });

  int d;
  cin >> d;

  int ans = 0;
  priority_queue<int, vector<int>, greater<>> pq;
  auto it = lines.begin();
  while (it != lines.end()) {
    auto [h, o] = *it++;
    while (!pq.empty() && pq.top() < o - d) pq.pop();
    if (o <= h + d) {
      pq.push(h);
      ans = max<int>(ans, pq.size());
    }
  }

  cout << ans;

  return 0;
}
