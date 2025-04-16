// Title : K번째 수
// Link  : https://www.acmicpc.net/problem/1300 
// Time  : 8 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

bool Check(int x, int n, int k) {
  int64_t cnt = 0;
  int limit = min<int>(x, n);
  for (int i = 1; i <= limit; i++) {
    cnt += min<int>(x / i, n);
  }
  return cnt < k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int lo = 0, hi = 1e9;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Check(mid, n, k)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  cout << hi;

  return 0;
}
