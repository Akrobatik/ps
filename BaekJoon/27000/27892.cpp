// Title : 특별한 큰 분수
// Link  : https://www.acmicpc.net/problem/27892 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t x, n;
  cin >> x >> n;
  bool skip = true;
  map<int64_t, int> memo;
  while (n--) {
    if (x & 1) {
      x = (x << 1) ^ 6;
    } else {
      x = (x >> 1) ^ 6;
    }

    if (skip) {
      if (auto it = memo.find(x); it != memo.end()) {
        int cycle = it->second - n;
        n %= cycle;
      } else {
        memo[x] = n;
      }
    }
  }
  cout << x;

  return 0;
}
