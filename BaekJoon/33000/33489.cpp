// Title : 수열의 점수
// Link  : https://www.acmicpc.net/problem/33489 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> fib{0, 1};
  while (fib.back() < 1000000) fib.push_back(fib.back() + fib[fib.size() - 2]);
  reverse(fib.begin(), fib.end());

  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y) {
      auto it = lower_bound(fib.begin(), fib.end(), y, greater<int>());
      y = *it;
      x = min<int>(x, *--it);
    } else {
      auto it = lower_bound(fib.begin(), fib.end(), x, greater<int>());
      x = *it;
      y = min<int>(y, *--it);
    }
    cout << max<int>(x, 1) << " " << max<int>(y, 1) << "\n";
  }

  return 0;
}
