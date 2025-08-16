// Title : 기울기가 가장 큰 두 점
// Link  : https://www.acmicpc.net/problem/1858 
// Time  : 12 ms
// Memory: 2616 KB

#include <bits/stdc++.h>

using namespace std;

using tup = tuple<int, int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<tup> arr(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr[i] = {x, y, i + 1};
  }
  sort(arr.begin(), arr.end());

  int ul = 0, ur = 1;
  pair<int, int> up = {get<2>(arr[0]), get<2>(arr[1])};
  if (up.first > up.second) swap(up.first, up.second);
  for (int i = 2; i < n; i++) {
    auto [lx, ly, li] = arr[ul];
    auto [rx, ry, ri] = arr[ur];
    auto [ix, iy, ii] = arr[i - 1];
    auto [jx, jy, ji] = arr[i];
    int64_t x1 = rx - lx, y1 = ry - ly;
    int64_t x2 = jx - ix, y2 = jy - iy;
    int64_t v1 = y1 * x2, v2 = y2 * x1;
    if (v1 < v2) {
      ul = i - 1, ur = i;
      up = {ii, ji};
      if (up.first > up.second) swap(up.first, up.second);
    } else if (v1 == v2) {
      pair<int, int> tmp = {ii, ji};
      if (tmp.first > tmp.second) swap(tmp.first, tmp.second);
      if (up > tmp) ul = i - 1, ur = i, up = tmp;
    }
  }

  int bl = 0, br = 1;
  pair<int, int> bp = {get<2>(arr[0]), get<2>(arr[1])};
  if (bp.first > bp.second) swap(bp.first, bp.second);
  for (int i = 2; i < n; i++) {
    auto [lx, ly, li] = arr[bl];
    auto [rx, ry, ri] = arr[br];
    auto [ix, iy, ii] = arr[i - 1];
    auto [jx, jy, ji] = arr[i];
    int64_t x1 = rx - lx, y1 = ry - ly;
    int64_t x2 = jx - ix, y2 = jy - iy;
    int64_t v1 = y1 * x2, v2 = y2 * x1;
    if (v1 > v2) {
      bl = i - 1, br = i;
      bp = {ii, ji};
      if (bp.first > bp.second) swap(bp.first, bp.second);
    } else if (v1 == v2) {
      pair<int, int> tmp = {ii, ji};
      if (tmp.first > tmp.second) swap(tmp.first, tmp.second);
      if (bp > tmp) bl = i - 1, br = i, bp = tmp;
    }
  }

  auto Inc = [&]() -> pair<int, int> {
    auto [lx, ly, li] = arr[ul];
    auto [rx, ry, ri] = arr[ur];
    if (ly > ry) return {INT_MAX, INT_MAX};

    int memo[3] = {li, ri, INT_MAX};
    sort(memo, memo + 3);
    for (auto [ix, iy, ii] : arr) {
      if (ii == li || ii == ri) continue;
      int64_t x1 = rx - lx, y1 = ry - ly;
      int64_t x2 = ix - rx, y2 = iy - ry;
      int64_t v1 = y1 * x2, v2 = y2 * x1;
      if (v1 == v2) {
        memo[2] = ii;
        sort(memo, memo + 3);
      }
    }
    return {memo[0], memo[1]};
  };

  auto Dec = [&]() -> pair<int, int> {
    auto [lx, ly, li] = arr[bl];
    auto [rx, ry, ri] = arr[br];
    if (ly < ry) return {INT_MAX, INT_MAX};

    int memo[3] = {li, ri, INT_MAX};
    sort(memo, memo + 3);
    for (auto [ix, iy, ii] : arr) {
      if (ii == li || ii == ri) continue;
      int64_t x1 = rx - lx, y1 = ry - ly;
      int64_t x2 = ix - rx, y2 = iy - ry;
      int64_t v1 = y1 * x2, v2 = y2 * x1;
      if (v1 == v2) {
        memo[2] = ii;
        sort(memo, memo + 3);
      }
    }
    return {memo[0], memo[1]};
  };

  auto [ulx, uly, uli] = arr[ul];
  auto [urx, ury, uri] = arr[ur];
  auto [blx, bly, bli] = arr[bl];
  auto [brx, bry, bri] = arr[br];

  int64_t x1 = urx - ulx, y1 = ury - uly;
  int64_t x2 = brx - blx, y2 = bly - bry;
  int64_t v1 = y1 * x2, v2 = y2 * x1;
  if (v1 < v2) {
    auto [a, b] = Dec();
    cout << a << " " << b;
  } else if (v1 > v2) {
    auto [a, b] = Inc();
    cout << a << " " << b;
  } else {
    auto up = Inc(), bp = Dec();
    if (up > bp) up = bp;
    cout << up.first << " " << up.second;
  }

  return 0;
}
