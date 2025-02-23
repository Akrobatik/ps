#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool memo[1000][1000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> m >> n;
  int rem = 0;
  queue<pair<int, int>> q;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      int v;
      cin >> v;
      if (v == 1) {
        memo[y][x] = true;
        q.push({y, x});
      } else if (v == 0) {
        ++rem;
      } else {
        memo[y][x] = true;
      }
    }
  }

  int i;
  for (i = 0; rem && !q.empty(); i++) {
    int nq = q.size();
    while (nq--) {
      auto [y, x] = q.front();
      q.pop();

      for (auto [dy, dx] : kDelta) {
        int yy = y + dy, xx = x + dx;
        if (0 <= yy & yy < n && 0 <= xx && xx < m && !memo[yy][xx]) {
          --rem;
          memo[yy][xx] = true;
          q.push({yy, xx});
        }
      }
    }
  }

  if (rem) {
    cout << "-1";
  } else {
    cout << i;
  }

  return 0;
}
