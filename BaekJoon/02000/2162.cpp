// Title : 선분 그룹
// Link  : https://www.acmicpc.net/problem/2162
// Time  : 28 ms
// Memory: 2212 KB

#include <bits/stdc++.h>

using namespace std;

struct Point {
  constexpr auto operator<=>(const Point& rhs) const {
    return x != rhs.x ? x <=> rhs.x : y <=> rhs.y;
  }

  int x, y;
};

struct Line {
  Point p1, p2;
};

int CCW(const Point& a, const Point& b, const Point& c) {
  int64_t cp = (int64_t)(b.x - a.x) * (int64_t)(c.y - a.y) - (int64_t)(b.y - a.y) * (int64_t)(c.x - a.x);
  return (cp > 0) - (cp < 0);
}

bool IsIntersect(const Line& l1, const Line& l2) {
  auto [a, b] = l1;
  auto [c, d] = l2;

  int abc = CCW(a, b, c);
  int abd = CCW(a, b, d);
  int cda = CCW(c, d, a);
  int cdb = CCW(c, d, b);

  if (abc == 0 && abd == 0) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return c <= b && a <= d;
  }
  return abc * abd <= 0 && cda * cdb <= 0;
}

int ans1, ans2 = 1;
int memo[3000][2];

int Find(int id) {
  while (id != memo[id][0]) {
    int parent = memo[id][0];
    memo[id][0] = memo[parent][0];
    id = parent;
  }
  return id;
}

void Union(int a, int b) {
  int pa = Find(a);
  int pb = Find(b);
  if (pa == pb) return;

  --ans1;
  if (memo[pa][1] < memo[pb][1]) swap(pa, pb);
  memo[pb][0] = pa;
  memo[pa][1] += memo[pb][1];
  if (ans2 < memo[pa][1]) ans2 = memo[pa][1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Line> lines(n);
  for (int i = 0; i < n; i++) {
    cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
    memo[i][0] = i;
    memo[i][1] = 1;
  }

  ans1 = n;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (IsIntersect(lines[i], lines[j])) Union(i, j);
    }
  }

  cout << ans1 << "\n"
       << ans2;

  return 0;
}
