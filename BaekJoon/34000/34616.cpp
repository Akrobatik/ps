// Title : Hoven
// Link  : https://www.acmicpc.net/problem/34616 
// Time  : 396 ms
// Memory: 18276 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  if (accumulate(arr.begin(), arr.end(), 0LL) <= k) {
    cout << "0\n"
         << n << "\n";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    return 0;
  }

  auto Calc = [&](int64_t x) -> int64_t {
    deque<pair<int64_t, int64_t>> dq;
    int64_t y = x << 1 | 1, minn = kInf;
    for (int i = 1; i <= n; i++) {
      while (!dq.empty() && dq.front().first + y < i) dq.pop_front();
      int64_t val = arr[i];
      if (i > x + 1) val += dq.front().second;

      while (!dq.empty() && dq.back().second >= val) dq.pop_back();
      dq.push_back({i, val});

      if (i >= n - x) minn = min<int64_t>(minn, val);
    }
    return minn;
  };

  auto Print = [&](int64_t x) {
    vector<int> memo(n + 1);
    deque<pair<int64_t, int64_t>> dq;
    int64_t st = 0, y = x << 1 | 1, minn = kInf;
    for (int i = 1; i <= n; i++) {
      while (!dq.empty() && dq.front().first + y < i) dq.pop_front();
      int64_t val = arr[i];
      if (i > x + 1) {
        auto [pi, pv] = dq.front();
        val += pv;
        memo[i] = pi;
      }

      while (!dq.empty() && dq.back().second >= val) dq.pop_back();
      dq.push_back({i, val});

      if (i >= n - x && minn > val) minn = val, st = i;
    }

    vector<int> ans;
    while (st > 0) {
      ans.push_back(st);
      st = memo[st];
    }

    cout << x << "\n"
         << ans.size() << "\n";
    for (auto e : views::reverse(ans)) cout << e << " ";
  };

  int64_t lo = 0, hi = n;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Calc(mid) > k) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  Print(hi);

  return 0;
}