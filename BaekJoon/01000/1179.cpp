// Title : 마지막 요세푸스 문제
// Link  : https://www.acmicpc.net/problem/1179 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, k;
  cin >> n >> k;
  int64_t ans = 1, idx = 1;
  if (k == 1) {
    cout << n;
    return 0;
  }

  for (;;) {
    int64_t step = (idx - ans) / (k - 1) + 1;
    if (idx + step > n) {
      ans += (n - idx) * k;
      break;
    }
    idx += step;
    ans = (ans + step * k) % idx;
    if (ans == 0) ans = idx;
  }
  cout << ans;

  return 0;
}
