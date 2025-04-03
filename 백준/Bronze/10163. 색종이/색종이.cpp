#include <bits/stdc++.h>

using namespace std;

int m[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int k = 1; k <= n; k++) {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        m[y + i][x + j] = k;
      }
    }
  }

  int cnts[101] = {};
  for (auto& r : m) {
    for (auto e : r) ++cnts[e];
  }

  for (int i = 1; i <= n; i++) {
    cout << cnts[i] << "\n";
  }

  return 0;
}
