// Title : 창하의 급식실 탁자 이야기
// Link  : https://www.acmicpc.net/problem/34025 
// Time  : 20 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, one = 0;
  bool odd = false;
  bool first = true;
  cin >> n;
  int64_t sum = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x == 1) {
      ++one;
    } else {
      if (x & 1) odd = true;

      if (first) {
        sum += x;
        first = false;
      } else {
        sum += x + 2;
      }
    }
  }

  int64_t cnt = (sum + 1) >> 1;
  if (one > 0) {
    cnt += one + (sum != 0 && (sum & 1) == 0 && !odd);
  }
  cout << cnt;

  return 0;
}