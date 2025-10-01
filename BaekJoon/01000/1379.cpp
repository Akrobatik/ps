// Title : 강의실 2
// Link  : https://www.acmicpc.net/problem/1379 
// Time  : 72 ms
// Memory: 6428 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tup> arr(n);
  for (auto& [s, e, id] : arr) cin >> id >> s >> e;
  sort(arr.begin(), arr.end());

  int m = n << 1;
  vector<pair<int, int>> axr;
  axr.reserve(m);
  for (auto [s, e, id] : arr) {
    axr.push_back({s, 1});
    axr.push_back({e, -1});
  }
  sort(axr.begin(), axr.end());

  int cur = 0, maxx = 0;
  for (auto [x, y] : axr) {
    cur += y;
    maxx = max<int>(maxx, cur);
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (int i = 1; i <= maxx; i++) {
    pq.push({0, i});
  }

  vector<int> ans(n + 1);
  for (auto [s, e, id] : arr) {
    auto [me, mi] = pq.top();
    pq.pop();

    ans[id] = mi;
    pq.push({e, mi});
  }

  cout << maxx << "\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}