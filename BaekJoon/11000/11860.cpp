// Title : Squares
// Link  : https://www.acmicpc.net/problem/11860 
// Time  : 0 ms
// Memory: 2024 KB

#include <bits/stdc++.h>

using namespace std;

array<pair<double, double>, 4> GetSquare(int cx, int cy, int vx, int vy) {
  int dx1 = vx - cx, dy1 = vy - cy;
  int dx2 = -dy1, dy2 = dx1;

  array<pair<double, double>, 4> res;
  res[0] = {cx + dx1, cy + dy1};
  res[1] = {cx + dx2, cy + dy2};
  res[2] = {cx - dx1, cy - dy1};
  res[3] = {cx - dx2, cy - dy2};
  return res;
}

pair<double, double> GetCrossPoint(const pair<double, double>& a1, const pair<double, double>& a2, const pair<double, double>& b1, const pair<double, double>& b2) {
  auto [ax, ay] = a1;
  auto [bx, by] = a2;
  auto [cx, cy] = b1;
  auto [dx, dy] = b2;
  auto x1 = bx - ax, x2 = cx - dx, x3 = cx - ax;
  auto y1 = by - ay, y2 = cy - dy, y3 = cy - ay;
  auto t = (x3 * y2 - y3 * x2) / (x1 * y2 - y1 * x2);
  return {ax + t * (bx - ax), ay + t * (by - ay)};
}

double CrossProduct(const pair<double, double>& a, const pair<double, double>& b, const pair<double, double>& c) {
  auto [ax, ay] = a;
  auto [bx, by] = b;
  auto [cx, cy] = c;
  return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

vector<pair<double, double>> Convex(const vector<pair<double, double>>& poly, const array<pair<double, double>, 4>& clip) {
  vector<pair<double, double>> memo = poly;
  for (int i = 0; i < 4; i++) {
    auto i1 = clip[i], i2 = clip[(i + 1) % 4];
    vector<pair<double, double>> mnxt;
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

double CalcArea(const vector<pair<double, double>>& pts) {
  double sum = 0.0;
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

  int n;
  cin >> n;
  vector<array<pair<double, double>, 4>> sqrs(n);
  for (auto& sqr : sqrs) {
    double cx, cy, vx, vy;
    cin >> cx >> cy >> vx >> vy;
    double dx1 = vx - cx, dy1 = vy - cy;
    double dx2 = -dy1, dy2 = dx1;

    sqr[0] = {cx + dx1, cy + dy1};
    sqr[1] = {cx + dx2, cy + dy2};
    sqr[2] = {cx - dx1, cy - dy1};
    sqr[3] = {cx - dx2, cy - dy2};
  }

  double sum = 0.0;
  int limit = 1 << n;
  vector<int> cands;
  for (int i = 1; i < limit; i++) {
    cands.clear();
    int x = i;
    while (x) {
      int lsb = x & (-x);
      cands.push_back(countr_zero((uint32_t)lsb));
      x ^= lsb;
    }

    vector<pair<double, double>> poly(sqrs[cands[0]].begin(), sqrs[cands[0]].end());
    for (int j = 1; j < cands.size(); j++) {
      poly = Convex(poly, sqrs[cands[j]]);
    }

    double sign = (cands.size() & 1) ? 1.0 : -1.0;
    sum += CalcArea(poly) * sign;
  }
  cout << (int)round(sum / 2.0);

  return 0;
}