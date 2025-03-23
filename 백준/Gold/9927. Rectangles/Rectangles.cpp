#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> coords[32767];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    for (int i = y1; i < y2; i++) {
      coords[i].push_back({x1, x2});
    }
  }

  int sum = 0;
  for (int i = 0; i < 32767; i++) {
    if (coords[i].empty()) continue;
    sort(coords[i].begin(), coords[i].end());
    int l = 0;
    for (auto [x1, x2] : coords[i]) {
      sum += max<int>(x2, l) - max<int>(x1, l);
      l = max<int>(l, x2);
    }
  }
  cout << sum;

  return 0;
}
