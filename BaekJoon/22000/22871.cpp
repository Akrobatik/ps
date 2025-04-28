// Title : 징검다리 건너기 (large)
// Link  : https://www.acmicpc.net/problem/22871 
// Time  : 24 ms
// Memory: 2164 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  vector<int64_t> memo(n);
  for (int i = 1; i < n; i++) {
    memo[i] = INT64_MAX;
    for (int j = 0; j < i; j++) {
      int64_t x = max<int64_t>(memo[j], (int64_t)(i - j) * (abs(arr[i] - arr[j]) + 1));
      memo[i] = min<int64_t>(memo[i], x);
    }
  }
  cout << memo[n - 1];

  return 0;
}
