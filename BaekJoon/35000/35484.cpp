// Title : 루미의 생일 파티장 찾아가기
// Link  : https://www.acmicpc.net/problem/35484 
// Time  : 40 ms
// Memory: 19756 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto Query = [&](int a, int b, int d) {
    cout << "? " << a << " " << b << " " << min<int>(d, n) << endl;

    int res;
    cin >> res;
    return res;
  };

  int lo = 0, hi = 512;
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (Query(0, n, mid) == 0) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  int ans = (hi << 1) - (Query(1, n, lo) ? 1 : 0);
  cout << "! " << ans << endl;

  return 0;
}