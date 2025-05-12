// Title : 순위 계산
// Link  : https://www.acmicpc.net/problem/17449 
// Time  : 24 ms
// Memory: 2804 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, n;
  cin >> r >> n;
  vector<int> arr(n);
  for (auto& e : arr) cin >> e;

  int minn = r, maxx = r, cnt = 0;
  for (auto e : arr) {
    maxx += (e <= maxx);
    if (e < minn) {
      ++minn;
    } else if (e == minn) {
      ++cnt;
    } else if (e <= minn + cnt) {
      int d = e - minn;
      cnt -= d - 1;
      minn += d;
    }
  }
  cout << minn << " " << maxx;

  return 0;
}
