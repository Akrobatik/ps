// Title : 나이트의 이동
// Link  : https://www.acmicpc.net/problem/33613
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, sy, sx;
  cin >> n >> sy >> sx;
  if (n == 3 && sy == 2 && sx == 2) {
    cout << 1;
    return 0;
  }

  int64_t x = n * n;
  cout << (x >> 1) + (n != 3 && x % 2 == 1 && (sy + sx) % 2 == 0);

  return 0;
}
