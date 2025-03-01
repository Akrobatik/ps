#include <bits/stdc++.h>

using namespace std;

constexpr pair<int, int> kDelta[] = {
    {0, 0},
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

int n, ans = INT_MAX;
int costs[10][10];
bool checked[10][10];

void Traverse(int st, int cnt, int sum) {
  if (cnt == 3) {
    if (ans > sum) ans = sum;
    return;
  }

  int maxx = (n - 2) * (n - 2);
  for (int i = st; i < maxx; i++) {
    int y = i / (n - 2) + 1, x = i % (n - 2) + 1;
    bool ok = true;
    for (auto [dy, dx] : kDelta) {
      if (!checked[y + dy][x + dx]) continue;
      ok = false;
      break;
    }
    if (!ok) continue;

    int csum = 0;
    for (auto [dy, dx] : kDelta) {
      checked[y + dy][x + dx] = true;
      csum += costs[y + dy][x + dx];
    }
    Traverse(i + 1, cnt + 1, sum + csum);
    for (auto [dy, dx] : kDelta) checked[y + dy][x + dx] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> costs[i][j];
    }
  }

  Traverse(0, 0, 0);
  cout << ans;

  return 0;
}
