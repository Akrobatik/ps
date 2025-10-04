// Title : 진우의 민트초코우유
// Link  : https://www.acmicpc.net/problem/20208 
// Time  : 144 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, h;
  cin >> n >> m >> h;

  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (x == 1) {
        arr.insert(arr.begin(), {i, j});
      } else if (x == 2) {
        arr.push_back({i, j});
      }
    }
  }

  auto [sy, sx] = arr[0];
  int na = arr.size(), maxx = 0;
  do {
    int rem = m;
    for (int i = 1; i < na; i++) {
      auto [y1, x1] = arr[i - 1];
      auto [y2, x2] = arr[i];

      int d1 = abs(y1 - y2) + abs(x1 - x2);
      if (rem < d1) break;
      rem += h - d1;

      int d2 = abs(sy - y2) + abs(sx - x2);
      if (rem >= d2) maxx = max<int>(maxx, i);
    }
  } while (next_permutation(arr.begin() + 1, arr.end()));
  cout << maxx;

  return 0;
}