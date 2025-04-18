// Title : 88888
// Link  : https://www.acmicpc.net/problem/33756 
// Time  : 48 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int Count(int64_t x) {
  int res = 0;

  int64_t mask = 111111111111111111l;
  while (mask) {
    int cnt = x / mask;
    res += cnt;
    x -= mask * cnt;
    mask /= 10;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int64_t x;
    cin >> x;
    cout << (x % 8 == 0 && Count(x >> 3) <= 8 ? "Yes\n" : "No\n");
  }

  return 0;
}