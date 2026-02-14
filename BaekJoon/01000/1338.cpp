// Title : 알 수 없는 번호
// Link  : https://www.acmicpc.net/problem/1338 
// Time  : 0 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t l, r, x, y;
  cin >> l >> r >> x >> y;
  if (l > r) swap(l, r);

  if (!(0 <= y && y < abs(x))) {
    cout << "Unknwon Number";
    return 0;
  }

  int64_t v = l % x;
  if (v < 0) v += x;
  v = l + (v <= y ? y - v : x + y - v);

  if (!(l <= v && v <= r)) {
    cout << "Unknwon Number";
  } else if (l <= (v + x) && (v + x) <= r) {
    cout << "Unknwon Number";
  } else {
    cout << v;
  }

  return 0;
}