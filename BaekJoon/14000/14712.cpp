// Title : 넴모넴모 (Easy)
// Link  : https://www.acmicpc.net/problem/14712 
// Time  : 180 ms
// Memory: 2020 KB

#include <bits/stdc++.h>

using namespace std;

int n, m, limit, ans;
bool board[25][25];
pair<int, int> xy[25];

bool Check(int y, int x) {
  if (y == 0 || x == 0) return true;
  return !board[y - 1][x - 1] || !board[y - 1][x] || !board[y][x - 1];
}

void Traverse(int idx) {
  if (idx == limit) {
    ++ans;
    return;
  }

  auto [y, x] = xy[idx];
  Traverse(idx + 1);
  if (Check(y, x)) {
    board[y][x] = true;
    Traverse(idx + 1);
    board[y][x] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  n, m;
  cin >> n >> m;
  limit = n * m;

  for (int i = 0; i < limit; i++) {
    int y = i / m, x = i % m;
    xy[i] = {y, x};
  }

  Traverse(0);
  cout << ans;

  return 0;
}
