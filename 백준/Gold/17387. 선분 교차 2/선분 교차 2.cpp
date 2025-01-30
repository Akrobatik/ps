#include <bits/stdc++.h>

using namespace std;

int64_t CrossProduct(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
  int64_t avx = ax2 - ax1;
  int64_t avy = ay2 - ay1;
  int64_t bvx = bx2 - bx1;
  int64_t bvy = by2 - by1;
  return avx * bvy - bvx * avy;
}

int GetDirection(int64_t cross) {
  return cross == 0 ? 0 : cross > 0 ? 1
                                    : -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

  int64_t c134 = CrossProduct(x1, y1, x3, y3, x1, y1, x4, y4);
  int64_t c234 = CrossProduct(x2, y2, x3, y3, x2, y2, x4, y4);
  int64_t c312 = CrossProduct(x3, y3, x1, y1, x3, y3, x2, y2);
  int64_t c412 = CrossProduct(x4, y4, x1, y1, x4, y4, x2, y2);
  int b134 = GetDirection(c134);
  int b234 = GetDirection(c234);
  int b312 = GetDirection(c312);
  int b412 = GetDirection(c412);

  if (b134 == 0 && b234 == 0 && b312 == 0 && b412 == 0) {
    pair<int, int> d1 = {x1, y1};
    pair<int, int> d2 = {x2, y2};
    pair<int, int> d3 = {x3, y3};
    pair<int, int> d4 = {x4, y4};
    if (d1 > d2) swap(d1, d2);
    if (d3 > d4) swap(d3, d4);
    cout << (d3 <= d2 && d1 <= d4) << endl;
  } else {
    cout << (b134 * b234 <= 0 && b312 * b412 <= 0) << endl;
  }

  return 0;
}
