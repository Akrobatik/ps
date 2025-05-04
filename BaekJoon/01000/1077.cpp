// Title : 넓이
// Link  : https://www.acmicpc.net/problem/1077 
// Time  : 0 ms
// Memory: 2156 KB

#include <bits/stdc++.h>

using namespace std;

pair<long double, long double> GetCrossPoint(const pair<long double, long double>& a1, const pair<long double, long double>& a2, const pair<long double, long double>& b1, const pair<long double, long double>& b2) {
  auto [ax, ay] = a1;
  auto [bx, by] = a2;
  auto [cx, cy] = b1;
  auto [dx, dy] = b2;
  auto x1 = bx - ax, x2 = cx - dx, x3 = cx - ax;
  auto y1 = by - ay, y2 = cy - dy, y3 = cy - ay;
  auto t = (x3 * y2 - y3 * x2) / (x1 * y2 - y1 * x2);
  return {ax + t * (bx - ax), ay + t * (by - ay)};
}

long double CrossProduct(const pair<long double, long double>& a, const pair<long double, long double>& b, const pair<long double, long double>& c) {
  auto [ax, ay] = a;
  auto [bx, by] = b;
  auto [cx, cy] = c;
  return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

vector<pair<long double, long double>> Convex(const vector<pair<long double, long double>>& poly, const vector<pair<long double, long double>>& clip) {
  vector<pair<long double, long double>> memo = poly;
  for (int i = 0; i < clip.size(); i++) {
    auto i1 = clip[i], i2 = clip[(i + 1) % clip.size()];
    vector<pair<long double, long double>> mnxt;
    for (int j = 0; j < memo.size(); j++) {
      auto j1 = memo[(j + 1) % memo.size()], j2 = memo[j];
      bool b1 = (CrossProduct(i1, i2, j1) >= 0.0), b2 = (CrossProduct(i1, i2, j2) >= 0.0);
      if (b1 != b2) mnxt.push_back(GetCrossPoint(i1, i2, j1, j2));
      if (b1) mnxt.push_back(j1);
    }
    memo.swap(mnxt);
  }
  return memo;
}

long double CalcArea(const vector<pair<long double, long double>>& pts) {
  long double sum = 0.0;
  for (int i = 0; i < pts.size(); i++) {
    auto [ix, iy] = pts[i];
    auto [jx, jy] = pts[(i + 1) % pts.size()];
    sum += ix * jy - iy * jx;
  }
  return abs(sum);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<pair<long double, long double>> poly(n);
  for (auto& [x, y] : poly) cin >> x >> y;

  vector<pair<long double, long double>> clip(m);
  for (auto& [x, y] : clip) cin >> x >> y;

  poly = Convex(poly, clip);
  long double sum = CalcArea(poly);
  cout << setprecision(9) << fixed << (sum / 2.0L);

  return 0;
}
