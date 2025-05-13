// Title : 아이템 2
// Link  : https://www.acmicpc.net/problem/31838 
// Time  : 72 ms
// Memory: 37180 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int64_t> arr(n + (k << 1));
  for (int i = 0; i < n; i++) {
    cin >> arr[i + k];
  }
  partial_sum(arr.begin(), arr.end(), arr.begin());

  vector<array<int64_t, 2>> memo(n + (k << 1));
  for (int i = k; i < memo.size(); i++) {
    memo[i][0] = max<int64_t>(memo[i - 1][0], memo[i - 1][1]);
    memo[i][1] = max<int64_t>(memo[i - 1][1] + arr[i] - arr[i - 1], memo[i - k][0] + arr[i] - arr[i - k]);
  }
  cout << max<int64_t>(memo.back()[0], memo.back()[1]);

  return 0;
}
