// Title : 시장조성하기
// Link  : https://www.acmicpc.net/problem/34057 
// Time  : 844 ms
// Memory: 88036 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int64_t, int64_t, int64_t>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  int64_t sa = 0, sb = 0;
  for (auto& [a, b, x] : arr) {
    cin >> a >> b >> x;
    sa += a, sb += b;
    a = sa, b = sb;
  }

  sort(arr.begin(), arr.end(), [](const tup& lhs, const tup& rhs) {
    auto [la, lb, lx] = lhs;
    auto [ra, rb, rx] = rhs;
    return la > ra || (la == ra && lb < rb);
  });

  int64_t sum = 0;
  map<int64_t, int64_t> memo;
  for (auto [a, b, x] : arr) {
    int64_t rem = x;
    auto it = memo.upper_bound(b);
    if (it == memo.end() && !(a <= 0 && 0 <= b)) continue;
    while (rem && it != memo.end()) {
      int64_t cut = min<int64_t>(rem, it->second);
      sum -= cut, rem -= cut;
      if ((it->second -= cut) == 0) it = memo.erase(it);
    }
    memo[b] += x, sum += x;
  }
  cout << sum;

  return 0;
}
