// Title : K번째 수
// Link  : https://www.acmicpc.net/problem/1300 
// Time  : 24 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int64_t x, int64_t n, int64_t k) {
  int64_t cnt = 0;
  int64_t limit = min<int64_t>(x, n);
  for (int64_t i = 1; i <= limit; i++) {
    cnt += min<int64_t>(x / i, n);
  }
  return cnt < k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;

  int64_t lo = 0, hi = 1e9;
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) >> 1;
    if (Check(mid, n, k)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << hi;

  return 0;
}
