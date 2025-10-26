// Title : 완전제곱수
// Link  : https://www.acmicpc.net/problem/1977 
// Time  : 0 ms
// Memory: 2032 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, r;
  cin >> l >> r;

  int minn = INT_MAX;
  int64_t sum = 0;
  for (int i = l; i <= r; i++) {
    int s = sqrt(i);
    while (s * s < i) ++s;

    if (s * s == i) {
      minn = min<int>(minn, i);
      sum += i;
    }
  }

  if (minn == INT_MAX) {
    cout << "-1";
  } else {
    cout << sum << "\n"
         << minn;
  }

  return 0;
}