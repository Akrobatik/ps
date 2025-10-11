// Title : Conditions
// Link  : https://www.acmicpc.net/problem/33270 
// Time  : 44 ms
// Memory: 2808 KB

#include <bits/stdc++.h>

using namespace std;

constexpr int64_t kInf = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto Check7 = [&](int64_t x) {
    while (x) {
      if (x % 10 == 7) return true;
      x /= 10;
    }
    return false;
  };

  auto Next7 = [&](int64_t x) {
    int64_t res = x;
    for (int64_t i = 0, d = 1; i < 18; i++, d *= 10) {
      if ((x / d) % 10 == 7) res = ((x / d) + 1) * d;
    }
    return res;
  };

  int64_t n, k;
  cin >> n >> k;

  vector<int64_t> arr(n);
  for (auto& e : arr) cin >> e;
  sort(arr.begin(), arr.end(), greater<int64_t>());

  int64_t l;
  cin >> l;

  while (!arr.empty() && arr.back() < l) arr.pop_back();
  reverse(arr.begin(), arr.end());
  n = arr.size();

  int64_t ans = INT64_MAX;
  for (auto e : arr) {
    if (e % k == 0 && !Check7(e)) {
      ans = e;
      break;
    }
  }

  int idx = 0;
  for (int64_t i = ((l + k - 1) / k) * k; i < ans; i += k) {
    while (idx < n && arr[idx] < i) ++idx;
    if (!(idx < n && arr[idx] == i) && Check7(i)) {
      ans = i;
      break;
    }
  }

  idx = 0;
  for (int64_t i = Next7(l); i < ans; i = Next7(i + 1)) {
    while (idx < n && arr[idx] < i) ++idx;
    if (!(idx < n && arr[idx] == i) && i % k != 0 && !Check7(i)) {
      ans = i;
      break;
    }
  }
  cout << ans;

  return 0;
}
