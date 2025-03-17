#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int64_t> arr(n), psum(n), memo(n);
  for (auto& e : arr) cin >> e;
  partial_sum(arr.begin(), arr.end(), psum.begin());

  memo[0] = arr[0];
  for (int i = 1; i < n; i++) {
    memo[i] = max<int64_t>(memo[i - 1], arr[i] - psum[i - 1]);
  }

  int64_t cnt = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > cur) {
      int64_t req = arr[i] - cur;
      int64_t add = req / memo[i] + (req % memo[i] != 0);
      cur += add * memo[i];
      cnt += add;
    }
    cur -= arr[i];
  }
  cout << cnt;

  return 0;
}
