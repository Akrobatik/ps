// Title : 구간 자르기
// Link  : https://www.acmicpc.net/problem/2283 
// Time  : 12 ms
// Memory: 6064 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int kMax = 1e6 + 1;

int memo[kMax + 1];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> arr(n);
  for (auto& [l, r] : arr) {
    cin >> l >> r;
    ++l, ++r;
  }
  sort(arr.begin(), arr.end());

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1, j = 0; i <= kMax; i++) {
    while (!pq.empty() && pq.top() <= i) pq.pop();
    while (j < n && arr[j].first == i) pq.push(arr[j++].second);
    memo[i] = memo[i - 1] + pq.size();
  }

  int l = 0, r = 0;
  while (l != kMax) {
    while (r < kMax && memo[r] - memo[l] < k) ++r;
    if (memo[min<int>(r, kMax)] - memo[l] == k) {
      cout << l << " " << r;
      return 0;
    }
    ++l;
  }
  cout << "0 0";

  return 0;
}
