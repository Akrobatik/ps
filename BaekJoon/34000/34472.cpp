// Title : 교도소
// Link  : https://www.acmicpc.net/problem/34472 
// Time  : 752 ms
// Memory: 6444 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;

  int64_t m = accumulate(arr.begin(), arr.end(), 0LL) / n;

  auto Cmp = [&](int lhs, int rhs) {
    return arr[lhs] < arr[rhs];
  };

  priority_queue<pair<int64_t, int>> pq;
  for (int i = 0; i < n; i++) {
    if (arr[i] > m) pq.push({arr[i], i});
  }

  int64_t cnt = 0;
  while (!pq.empty()) {
    auto [val, idx] = pq.top();
    pq.pop();

    if (arr[idx] != val) continue;

    int64_t cut = val - m;
    cnt += cut;
    arr[idx] -= cut;

    int nxt = idx + 1;
    if (nxt == n) nxt = 0;
    if ((arr[nxt] += cut) > m) pq.push({arr[nxt], nxt});
  }

  cout << cnt;

  return 0;
}