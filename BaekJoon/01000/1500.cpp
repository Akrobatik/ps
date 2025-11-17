// Title : 최대 곱
// Link  : https://www.acmicpc.net/problem/1500 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t s, k;
  cin >> s >> k;

  int64_t ans = 1;
  for (int i = 0; i < k; i++) {
    int64_t x = s / (k - i);
    ans *= x, s -= x;
  }
  cout << ans;

  return 0;
}