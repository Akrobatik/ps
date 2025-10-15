// Title : 여름나기
// Link  : https://www.acmicpc.net/problem/18130 
// Time  : 4 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, q;
  cin >> n >> q;

  int64_t minn = INT64_MAX, mi;
  for (int i = 1; i <= n; i++) {
    int64_t p, k, c;
    cin >> p >> k >> c;
    int64_t x = max<int64_t>((q + k - 1) / k - 1, 0);
    int64_t y = x * (x + 1) / 2;
    int64_t z = p + y * c;
    if (minn > z) minn = z, mi = i;
    minn = min<int64_t>(minn, z);
  }
  cout << mi << " " << minn;

  return 0;
}