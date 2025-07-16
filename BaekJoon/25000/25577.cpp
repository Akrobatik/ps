// Title : 열 정렬정렬 정
// Link  : https://www.acmicpc.net/problem/25577 
// Time  : 32 ms
// Memory: 2940 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;
  auto axr = arr;
  sort(axr.begin(), axr.end());

  for (auto& e : arr) e = (lower_bound(axr.begin(), axr.end(), e) - axr.begin());

  vector<bool> visited(n);
  int cnt = n;
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    --cnt;
    int cur = i;
    do {
      visited[cur] = true;
      cur = arr[cur];
    } while (!visited[cur]);
  }
  cout << cnt;

  return 0;
}
