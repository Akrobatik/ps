// Title : mapa
// Link  : https://www.acmicpc.net/problem/3225 
// Time  : 36 ms
// Memory: 2808 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int miny = INT_MAX, minx;
  vector<pair<int, int>> coords(n);
  for (auto& [y, x] : coords) {
    cin >> x >> y;
    y *= 3;
  }

  const pair<int, int> kSign[] = {
      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

  int ans = INT_MAX;
  for (auto [sy, sx] : kSign) {
    sort(coords.begin(), coords.end(), [&](const pair<int, int>& lhs, const pair<int, int>& rhs) {
      auto [ay, ax] = lhs;
      auto [by, bx] = rhs;
      return ay * sy + ax * sx < by * sy + bx * sx;
    });

    int cur = INT_MAX;
    for (int i = 1; i < n; i++) {
      auto [y1, x1] = coords[i - 1];
      auto [y2, x2] = coords[i];
      ans = min<int>(ans, max<int>(abs(y1 - y2), abs(x1 - x2)));
    }
  }

  int quot = ans / 3, rem = ans % 3;
  cout << quot << (rem == 0 ? ".00" : (rem == 1 ? ".33" : ".67"));

  return 0;
}
