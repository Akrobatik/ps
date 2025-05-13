// Title : Red and Blue
// Link  : https://www.acmicpc.net/problem/33805 
// Time  : 0 ms
// Memory: 2304 KB

#include <bits/stdc++.h>

using namespace std;

struct GrahamScan {
  void Init(span<pair<int, int>> coords) {
    swap(coords[0], *min_element(coords.begin(), coords.end()));
    auto [miny, minx] = *min_element(coords.begin(), coords.end());

    for (auto& [y, x] : coords) y -= miny, x -= minx;
    sort(coords.begin() + 1, coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      auto [ay, ax] = lhs;
      auto [by, bx] = rhs;
      int ccw = CCW(ay, ax, by, bx);
      assert(ccw != 0);
      return ccw ? ccw > 0 : (int64_t)ay + abs(ax) < (int64_t)by + abs(bx);
    });
    sort(coords.begin(), coords.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      auto [ay, ax] = lhs;
      auto [by, bx] = rhs;
      int ccw = CCW(ay, ax, by, bx);
      return ccw ? ccw > 0 : (int64_t)ay + abs(ax) < (int64_t)by + abs(bx);
    });
    for (auto& [y, x] : coords) y += miny, x += minx;

    vertices.clear(), inners.clear();
    for (auto c : coords) {
      auto rit = vertices.rbegin();
      while (vertices.size() >= 2 && CP(rit[0], rit[1], c) >= 0) inners.push_back(vertices.back()), vertices.pop_back(), ++rit;
      vertices.push_back(c);
    }
  }

  static int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx) {
    int64_t cp = ax * by - ay * bx;
    return (cp > 0) - (cp < 0);
  }

  static int CCW(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
    int64_t cp = CP(ay, ax, by, bx, cy, cx);
    return (cp > 0) - (cp < 0);
  }

  static int64_t CP(int64_t ay, int64_t ax, int64_t by, int64_t bx, int64_t cy, int64_t cx) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
  }

  static int64_t CP(const pair<int, int>& a, const pair<int, int>& b, const pair<int, int>& c) {
    return CP(a.first, a.second, b.first, b.second, c.first, c.second);
  }

  vector<pair<int, int>> vertices;
  vector<pair<int, int>> inners;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  map<pair<int, int>, int> memo;

  int n;
  cin >> n;
  vector<pair<int, int>> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].first >> pts[i].second;
    memo[pts[i]] = i + 1;
  }

  GrahamScan scan;
  scan.Init(pts);
  auto& outers = scan.vertices;
  auto& inners = scan.inners;
  if (inners.empty()) {
    cout << "-1";
    return 0;
  }

  auto [iy, ix] = inners.back();
  auto id = memo[inners.back()];
  inners.pop_back();

  pts.clear();
  pts.insert(pts.end(), outers.begin(), outers.end());
  pts.insert(pts.end(), inners.begin(), inners.end());

  sort(pts.begin(), pts.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
    auto [ly, lx] = lhs;
    auto [ry, rx] = rhs;
    return GrahamScan::CCW(iy, ix, ly, lx, ry, rx) < 0;
  });

  vector<int> pids(pts.size());
  for (int i = 0; i < pids.size(); i++) pids[i] = memo[pts[i]];

  vector<tuple<int, int, int>> ans;
  ans.reserve((n - 1) << 1);

  ans.push_back({pids[0], pids[1], 0});
  for (int i = 1; i < pids.size(); i++) ans.push_back({id, pids[i], 0});

  ans.push_back({id, pids[0], 1});
  for (int i = 2; i < pids.size(); i++) ans.push_back({pids[i - 1], pids[i], 1});
  ans.push_back({pids[0], pids.back(), 1});

  cout << ans.size() << "\n";
  for (auto [a, b, c] : ans) {
    cout << a << " " << b << " " << (c ? "R\n" : "B\n");
  }

  return 0;
}
