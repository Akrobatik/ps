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
