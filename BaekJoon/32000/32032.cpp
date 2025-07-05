// Title : 만보기 대행 서비스
// Link  : https://www.acmicpc.net/problem/32032 
// Time  : 124 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, d;
  cin >> n >> d;
  int64_t minn = INT_MAX, maxx = INT_MIN;
  while (n--) {
    int x;
    cin >> x;
    minn = min<int>(minn, x);
    maxx = max<int>(maxx, x);
  }

  int64_t x = abs(minn), y = abs(maxx), z = max<int64_t>((maxx - minn) * 2, d);
  if (x > y) swap(x, y);
  if (minn * maxx < 0) {
    cout << min<int64_t>({(x + y + d) * 2, x * 4 + y * 2 + d, x * 2 + y * 2 + z});
  } else {
    cout << y * 2 + d;
  }

  return 0;
}
